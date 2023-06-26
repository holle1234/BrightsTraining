#if !defined(LOGGER)
#define LOGGER

#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <filesystem>


namespace fs = std::filesystem;


// for writing and reading logs
namespace logger {


// LogWriter
class LogWriter{

    private:
        std::fstream fileObj;
    public:
        std::string filepath;


        // constructor
        LogWriter(std::string filepath){
            this->filepath = filepath;
        }
        ~LogWriter()
        {
            this->fileObj.close();
        }

        bool open(std::string&& mode = "w")
        {
            // select opening mode
            std::ios::openmode _mode;
            if (mode=="w"){_mode = std::ios::out;}
            else if (mode=="a"){_mode = std::ios::app;}
            else return false;

            // file must not be a directory if it exists
            if (fs::exists(filepath) && fs::is_directory(filepath)){
                return false;
            }

            // file must be open to use it
            fileObj.open(filepath, _mode);
            if (!fileObj.is_open()){return false;}

            return true;
        }
        void close()
        {
            fileObj.close();
        }

        // write one line of csv file
        void writeLine(std::string line)
        {
            fileObj << line << "\n";
        }

};

// LogReader
class LogReader{
    
    private:
        std::string filepath;
        std::fstream fileObj;
        bool _isOpen {true};
    public:
        LogReader(std::string filepath)
        {
            this->filepath = filepath;
        }
        ~LogReader()
        {
            this->fileObj.close();
        }

        bool open()
        {
            // file must not be a directory & it must exist!
            if (fs::is_directory(filepath) || !fs::exists(filepath)){
                return false;
            }

            // file must be open to use it
            fileObj.open(filepath, std::ios::in);
            if (!fileObj.is_open()){return false;}

            return true;
        }

        void close()
        {
            fileObj.close();
        }

        // read one line of csv file
        bool readLine(std::string &dest)
        {
            std::getline(fileObj, dest);
            _isOpen = bool(fileObj);
            return _isOpen;
        }
};


}


#endif // LOGGER
