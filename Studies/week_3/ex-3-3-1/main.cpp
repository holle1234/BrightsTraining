#include "utils/utils.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <ostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <limits>


const std::array<std::string, 4> CMD_HELP {"'-t'   --           print to terminal",
                                           "'-f'   [filepath]   print to file",
                                           "'-s'   [int]        start value to pascal",
                                           "'-d'   [int]        depth of the triangle"};



/* 
Use indexing from the previously calculated row to calculate new row.
Each index has one left parent and one right parent node. 
Left parent index in the previous row is current_node - 1;
Right parent index in the previous row is same as the current_node.
If left or right parent is not in the range it is valued as zero.
When indexes are found, counting current node's pascal is simple as
cur_val = preRow[lp] + preRow[rp].


This version of pascal triangle is able to count and draw pascal triangles
at least up to depth 30. Though depth 20 is max available terminal print.

   matrix
  size n*n
[1][0][0][0] initial row  
[1][1][0][0] next row
[1][2][1][0] -.-
[1][3][3][1] -.-


SAMPLE OUTPUT:

some/path& ./pascal -s 5 -d 4 -t -f ../pascal.txt

      5 

    5  5 

   5 10  5 

  5 15 15  5 


 */




int main(int argc, char const *argv[])
{

    const char** end {argv + argc};
    PascalVector pascalValues;

    int start {1};
    int depth {5};

    // if no args supplied print help
    if (argc == 1){
        for (auto &&i : CMD_HELP){
            std::cout << i << "\n";
        }
        exit(0);
    }

    // check if -s (start of the pascal triangle)
    {
        auto optLoc = optionExists(argv, end, "-s");
        if (optLoc != end){
            // integer should follow this option
            try{
                std::string strValue {*(optLoc + 1)};
                start = sToInt(strValue);
            }
            catch(const std::invalid_argument& e){
                std::cout << "Invalid argument to start option\n";
                std::exit(0);
            }
        }
    }
    // check if -d (depth of the pascal triangle)
    {
        auto optLoc = optionExists(argv, end, "-d");
        if (optLoc != end){
            // integer should follow this option
            try{
                std::string strValue {*(optLoc + 1)};
                depth = sToInt(strValue);
            }
            catch(const std::invalid_argument& e){
                std::cout << "Invalid argument to depth option\n";
                std::exit(0);
            }
        }
    }

    // compute pascal by user options
    pascal(pascalValues, start, depth);

    // check if -t (print to console/terminal)
    {    
        auto optLoc = optionExists(argv, end, "-t");
        if (optLoc != end){
            try{
                std::cout << "\n" << pascalValues;
            }
            catch(const std::invalid_argument& e){
                std::cout << "Too large to print to console! Printing is allowed only up to -d 20\n";
                exit(0);
            }
        }
    }

    // check if -f (print to a file)
    {    
        auto optLoc = optionExists(argv, end, "-f");
        if (optLoc != end){
            // filepath should follow this option
            if (optLoc + 1 != end){
                std::string filepath = *(optLoc + 1);
                if (!writePascalFile(filepath, pascalValues)) {
                    std::cout << "Something went wrong while writing to a file!\n";
                    std::exit(0);
                }
            }
        }
    }
    
    return 0;
}
