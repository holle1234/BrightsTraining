#if !defined(CSV)
#define CSV


#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <iterator>
#include <iostream>
#include <iomanip>


// all accessable via csv::
namespace csv {


// shorter reference to this namespace
namespace fs = std::filesystem;

// simplifies the usage of writer and reader
using StringRow = std::vector<std::string>;

// print row of csv formated as table
void pretty_print(csv::StringRow row, int max_size);



class CSVReader{
    private:
        std::string rawRow{""};
        std::string word{""};
        std::stringstream wordStream;
        std::string filepath;
        std::fstream fileObj;
        bool ignoreHeader{false};

        // used to ignore header
        void readLine(){
            std::getline(fileObj, rawRow);
        }

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

            return true;
        }

        void close()
        {
            fileObj.close();
        }

        // read one line of csv file
        bool readLine(StringRow &dest)
        {
            // check if there is something to read
            if (!bool(fileObj)){return false;}

            // read raw string line
            std::getline(fileObj, rawRow);

            // clear storages for new data
            wordStream.str("");

            // split string line to words
            split_to_words(rawRow, dest);

            return true;
        }

        void split_to_words(std::string& rawRaw, StringRow &dest){
            wordStream.clear();
            dest.clear();

            // split string line to words
            wordStream << rawRow;
            while (std::getline(wordStream, word, ','))
            {
                dest.push_back(word);
            }
        }

        // gets the last line of data from csv
        void read_last_line(StringRow &dest){

            // csv has a newline at the last position
            // seekg further -2
            fileObj.seekg(-2, std::ios_base::end); 

            while(true) {
                char ch;
                fileObj.get(ch);

                if (int(fileObj.tellg()) <= 1) {
                    fileObj.seekg(0); 
                    break;    
                }
                else if (ch == '\n') { 
                    break;
                }
                else {
                    fileObj.seekg(-2, std::ios_base::cur);
                }
            }
           
           readLine(dest);
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
        template<typename It>
        void writeLine(It begin, It end){
            if (!fileObj.is_open()){
                throw std::invalid_argument("could not open file " + filepath);
            }

            std::stringstream line;
            for (auto it = begin; it != end; it++){
                line << *it << ",";
            }

            // add new line and replace last ',' with '\n'
            std::string row {line.str()};
            row.resize(row.size() - 1);
            //row.replace(row.size() - 1, 1, "\n");
            fileObj << row << "\n" ; 
        }

};

};
#endif // CSV
