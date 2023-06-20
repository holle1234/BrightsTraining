#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>
#include <algorithm>


using IntVector = std::vector<int>;
namespace fs = std::filesystem;


IntVector readFile(const std::string& filename){
    IntVector vec;

    // check file existance and try to open it
    if(fs::exists(filename)){

        std::fstream fstream;
        fstream.open(filename, std::ios::in);

        std::string row;
        if(fstream.is_open()){
            while (std::getline(fstream, row)){

                // catch a non number
                try{
                    vec.push_back(std::stoi(row));
                }
                catch(const std::invalid_argument& e){
                    std::cerr << "oops not a number!" << '\n';
                }
            }
            
        }
    }

    return vec;
}


void sortIntVector(IntVector& intVect){
    std::sort(intVect.begin(), intVect.end());
}


// overload cout << intVectorfor ease printing
std::ostream &operator<<(std::ostream& os, const IntVector& intVect) {
    std::string out {"IntVector: ("};
    for (auto &&value : intVect){
        out += (std::to_string(value) + " ");
    }
    out += ")";
    return os << out;
}

int main(int argc, char const *argv[])
{
    std::string filename {"numbers.txt"};
    IntVector intVect = readFile(filename);
    std::cout << intVect << "\n";
    sortIntVector(intVect);
    std::cout << intVect << "\n";

    return 0;
}
