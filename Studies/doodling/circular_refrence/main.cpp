#include <iostream>
#include "source/struct.h"


// Showcase program for circular includes
// This program illustrates how that you can cross-reference files by including them to each other
// Uses a directory to store .cpp & .h files! Dont forget to change tasks.json!! ("${fileDirname}/source/*.cpp")

int main(int argc, char const *argv[])
{
    MyStruct st {100};
    st.structFunc();
    return 0;
}
