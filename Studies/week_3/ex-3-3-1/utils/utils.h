#if !defined(PASCAL_UTILS)
#define PASCAL_UTILS


#include <vector>
#include <string>


// alias for in vector iterator (for passing begin and end)
using PascalIterator = std::vector<int>::iterator;

// alias for in int vector
using PascalVector = std::vector<int>;

std::ostream &operator<<(std::ostream &os, PascalVector pVect);

// writes a single line of triangle to stream (not formated right yet!)
void writePascalRow(const PascalIterator &begin, const PascalIterator &end, std::stringstream &stream, int resSize);

int sToInt(std::string &s);

// find terminal option
const char** optionExists(const char **begin, const char **end, std::string opt);

bool writePascalFile(std::string &filepath, PascalVector &pascal);

// calculates the depth of triangle from array size
int calculateTriangleDepthFromVectorSize(int size);

// calculates how many characters it takes to print values at a depth x
int calculateCharRowWidth(int reservedSize, int depth);

// calculates the pascal values up to depth and adds them to vector
void pascal(PascalVector &vect, int start, int depth);

#endif // PASCAL_UTILS