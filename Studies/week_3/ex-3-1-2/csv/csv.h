#if !defined(CSV)
#define CSV


#include <vector>
#include <string>
#include <array>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <iterator>
#include <iostream>
#include <iomanip>


namespace fs = std::filesystem;

using StringRow = std::vector<std::string>;


std::ostream& operator<<(std::ostream& os, StringRow& row){
    for (auto it = row.begin(); it != row.end(); it++){
        os << std::setprecision(5) << *it;
    }
    return os;
}



// all accessable via csv::
namespace csv {

class CSVReader{
    private:
        std::string rawRow{""};
        std::string word{""};
        std::stringstream wordStream;
        std::string filepath;
        std::fstream fileObj;
        bool ignoreHeader{false};
        bool _isOpen {false};

    public:
        CSVReader(std::string filepath, bool ignoreHeader = false)
        {
            this->filepath = filepath;
            this->ignoreHeader = ignoreHeader;
        }
        ~CSVReader()
        {
            this->fileObj.close();
        }

        bool open()
        {
            // file must not be a directory & it must exist!
            if (!(!fs::is_directory(filepath) && fs::exists(filepath))){
                return false;
            }

            // file must be open to use it
            fileObj.open(filepath, std::ios::in);
            if (!fileObj.is_open()){return false;}

            // read one line early so it seem ignored to the caller
            if (ignoreHeader){readLine();}
            _isOpen = true;

            return true;
        }

        void close()
        {
            fileObj.close();
        }

        // used to ignore header
        void readLine()
        {
            std::getline(fileObj, rawRow);
        }

        // read one line of csv file
        bool readLine(StringRow &dest)
        {
            // clear containers
            wordStream.clear();
            dest.clear();

            // read raw string line
            if (std::getline(fileObj, rawRow))
            {
                // split string to out vector
                wordStream << rawRow;
                while (std::getline(wordStream, word, ','))
                {
                    dest.push_back(word);
                }
            };
            
            _isOpen = bool(fileObj);
            return _isOpen;
        }
};



class CSVWriter{
    
    private:
        std::string filepath;
        std::fstream fileObj;

    public:
        CSVWriter(std::string filepath)
        {
            this->filepath = filepath;
        }
        ~CSVWriter()
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
        template<typename Iterator>
        void writeLine(Iterator begin, Iterator end)
        {
            std::string line;
            auto it = begin;
            for (; it != (end - 1); it++)
            {
                line += (*it + ",");
            }
            line += (*it + "\n");
            fileObj << line;
        }

};

};
#endif // CSV
