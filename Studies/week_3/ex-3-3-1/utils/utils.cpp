#include "utils.h"
#include <algorithm>
#include <string>
#include <iomanip>
#include <filesystem>
#include <fstream>


namespace fs = std::filesystem;


std::ostream&operator<<(std::ostream& os, PascalVector pVect){

    std::stringstream ss;
    size_t size {pVect.size()};

    int depth = calculateTriangleDepthFromVectorSize(size);

    if (depth > 20){
        throw std::invalid_argument("Cant print pascal triangles beyond depth 20\n");
    }else if (depth < 1){
        throw std::invalid_argument("Cant print pascal triangles below depth 1\n");
    }

    // resize reserved size fir string representation (10 -> 2 || 100 -> 3..)
    // max element should reside in the last row
    int resSize {*std::max_element(pVect.end() - size , pVect.end())};
    resSize = std::to_string(resSize).size();

    /*Count the row width to set left pad size for each row
    left pad needs to adjusted from the size of characters each row reserves. */
    int rowHalfWidth = calculateCharRowWidth(resSize, depth) / 2;

    // form triangle
    auto begin = pVect.begin();
    for (size_t i = 1; i < depth + 1; i++){

        // copy next level to buffer with spaces between values
        writePascalRow(begin, begin + i, ss, resSize);
    
        // shift ss buffer to cout buffer with left paddded spaces
        int pad = calculateCharRowWidth(resSize, i) / 2 + 1;
        os << std::setw(rowHalfWidth + pad) << std::setfill(' ') << ss.str() << "\n";

        // clear buffer and set iterator to next 'row'
        ss.str(std::string());
        begin += i;
    }
    return os << "\n";
}


void writePascalRow(const PascalIterator& begin, const PascalIterator& end,
                 std::stringstream& stream, int resSize=5){

    std::string value(resSize, ' ');
    for (auto it = begin; it != end; it++){
        stream << std::setw(resSize) << std::setfill(' ') << *it << " ";
    }
    stream << "\n";
}


int sToInt(std::string& s){

    if (s.empty()){
        throw std::invalid_argument("Cant convert empty string to int");}
    return std::stoi(s);
}


const char** optionExists(const char** begin, const char** end, std::string opt){
    auto it = std::find_if(begin, end, [&](const std::string& a){return a == opt;});
    if (it != end){
        return it;
    }
    return end;
}


bool writePascalFile(std::string& filepath, PascalVector& pascal){
    if (!fs::is_directory(filepath)){

        std::fstream file;
        file.open(filepath, std::ios::out);

        if (file.is_open()){
            file << pascal;
            file.close();
            return true;
        }
    }
    return false;
}


int calculateTriangleDepthFromVectorSize(int size){
    int depth {1};
    for (depth = 1; size > 0; depth++){
        size -= depth;
    }
    
    if(size != 0){
        throw std::invalid_argument("not a right shaped pascal triangle");}
    
    return depth - 1;

}

int calculateCharRowWidth(int reservedSize, int depth){
    return (reservedSize * depth) + (depth + 1);
}



void pascal(PascalVector& vect, int start, int depth=3){

    // Dest vector must be empty to add values to it
    if (!std::empty(vect)){
        throw std::invalid_argument("Vector must be empty!\n");
    }else if (depth < 1){
        throw std::invalid_argument("Depth must be larger than 1!\n");
    }

    // set help vectors to retain prev and new row values
    PascalVector helpVect(depth);
    PascalVector newRowVect(depth);
    helpVect[0] = start;

    // start calculating values
    vect.push_back(start);
    for (int level = 1; level < depth; level++){

        // reset new row
        std::fill(newRowVect.begin(), newRowVect.end(), 0);

        for (int ind = 0; ind < (level + 1); ind++){
            int lp = ((ind - 1) >= 0) ? helpVect[ind - 1] : 0;
            int rp = (ind < level) ? helpVect[ind] : 0;
            int result = lp + rp;

            // add to dest vect
            vect.push_back(result);

            // set new value to current row
            newRowVect[ind] = result;
        }
        // update pre row values
        helpVect = newRowVect;
    }
    
}