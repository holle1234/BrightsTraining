#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <string_view>
#include <algorithm>


// alias for clearer access
namespace fs = std::filesystem;

// check suffix
static bool endsWith(std::string_view str, std::string_view suffix){
    return str.size() >= suffix.size() && 
            0 == str.compare(str.size()-suffix.size(), suffix.size(), suffix);
}

// search options from string
bool cmdOptionExists(char** begin, char** end, const std::string& option){
    return std::find(begin, end, option) != end;
}


// returns a word,char count pair
std::pair<int, int> wordCharCounter(std::string& line){
    // unpack line to words
    std::stringstream stream {line};
    std::string word {};

    // count words
    std::pair<int, int> pair {0, 0};
    while (std::getline(stream, word,  ' ')){
        pair.first++;
        pair.second += word.size();
    }
    return pair;
}


// file print function
void printFile(std::string filePath,
                bool countLines=false,
                bool countWords=false,
                bool countChars=false,
                bool countSize=false){

    fs::path path {filePath};

    if(!fs::exists(path)){
        std::cout << "File not found!\n";
        return;
    }
    if (!endsWith(filePath, ".txt")){
        std::cout << "File is not a .txt file!\n";
        return;
    }

    int lineCount {0};
    int wordCount {0};
    int charCount {0};

    std::ifstream inputFile(path);
    std::string line {""};

    if (!inputFile.is_open()){
        return;
    }
    
    // print lines only if there were no flags
    while (std::getline(inputFile, line)){
        lineCount++;

        std::pair<int, int> wc_ch = wordCharCounter(line);
        wordCount += wc_ch.first;
        charCount += wc_ch.second;

        if(!(countLines || countWords || countChars || countSize)){
            std::cout << line << '\n';
        }
    }
        
    if (countLines){
        std::cout << "File has " << lineCount << " lines!\n";
    }
    if (countWords){
        std::cout << "File has " << wordCount << " words!\n";
    }
    if (countChars){
        std::cout << "File has " << charCount << " characters!\n";
    }
    if (countSize){
        std::string msg {"File size is "};
        std::string msgSuffix {" bytes"};

        // change to kilos
        int size = fs::file_size(filePath);
        if (size > 1000){
            size /= 1000.0;
            msgSuffix = " kilobytes";
        }
        std::cout << "File size is " << size << msgSuffix << "\n";
    }

    inputFile.close();
}


int main(int argc, char *argv[]){

    if(argc > 1){

        bool countLines = cmdOptionExists(argv, argv+argc, "--lines");
        bool countWords = cmdOptionExists(argv, argv+argc, "--words");
        bool countChars = cmdOptionExists(argv, argv+argc, "--chars");
        bool countSize = cmdOptionExists(argv, argv+argc, "--size");

        printFile(argv[1], countLines, countWords, countChars, countSize);
    }

    return 0;
}
