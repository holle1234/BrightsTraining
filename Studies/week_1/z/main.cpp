#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <vector>


// use these to store csv data
using csvMap = std::map<std::string, std::string>;
using csvVector = std::vector<csvMap>;

// Read csv to map, key is a column name 
// csv must have a header for this to work!
bool csvRead(std::string fileName, csvVector& dest){

    // open filestream
    std::fstream myFile;
    myFile.open(fileName, std::ios::in);

    if(!myFile.is_open()){
        return false;
    }

    std::vector<std::string> header;
    std::vector<std::string> row;
    std::string rawRow {""};
    std::string word {""};
    int rowIndex {0};

    // [word = split(line, ',') for line in stream(rawFileRow)]
    while (std::getline(myFile, rawRow)){
        std::stringstream stream {rawRow};
        while (std::getline(stream, word,  ',')){
            row.push_back(word);
        }

        // unpack non header rows
        if (rowIndex != 0){
            csvMap map;
            for (size_t i = 0; i < header.size(); i++){
                map[header[i]] = row[i];
            }
            dest.push_back(map);
        }
        // unpack header
        else header = row;

        row.clear();
        rowIndex++;
    }
    myFile.close();
    return true;
}


bool csvWrite(std::string fileName, const csvVector& data){

    // open filestream
    std::fstream myFile;
    myFile.open(fileName, std::ios::out);
    
    if(!myFile.is_open()){
        return false;
    }

    // write header first
    auto lastElement {data[0].rbegin()->first};
    for (auto &&i : data[0]){
        bool isLast {i.first == lastElement};
        myFile << i.first << ((isLast) ? "\n" : ",");
    }
    
    // write data rows
    for (auto &&mapObject : data){
        auto lastElement {mapObject.rbegin()->first};
        for (auto &&i : mapObject){
            bool isLast {i.first == lastElement};
            myFile << i.second << ((isLast) ? "\n" : ",");
        }
    }
    
    myFile.close();

    return true;
}



int main(int argc, char const *argv[])
{

    csvMap p1 {{"name", "juho"}, {"age", "20"}};
    csvMap p2 {{"name", "niina"}, {"age", "19"}};

    csvVector vect {p1, p2};
    csvWrite("test.csv", vect);

    csvVector readvect;
    csvRead("test.csv", readvect);
    csvWrite("read.csv", readvect);


    return 0;
}
