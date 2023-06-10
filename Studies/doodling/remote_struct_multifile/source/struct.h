#if !defined(HEADER)
#define HEADER

#include <string>

struct MyStruct
{
    int privateVar;
    // MyStruct structFunc declaration
    void structFunc(std::string);
};

#endif // HEADER
