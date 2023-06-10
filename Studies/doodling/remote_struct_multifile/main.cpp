#include <iostream>
#include "source/struct.h"


// Showcase program for multifile projects
// This program illustrates how struct member functions are defined in remote cpp.file
// Uses a directory to store .cpp & .h files! Dont forget to change tasks.json!! ("${fileDirname}/source/*.cpp")

int main(int argc, char const *argv[])
{
    MyStruct st;
    st.structFunc("with love from main");
    st.privateVar = 10;
    st.structFunc("after change");

    return 0;
}
