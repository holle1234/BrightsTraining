#include <iostream>
#include "header.h"


// Showcase program for multifile projects
// This program illustrates how struct member functions are defined in remote cpp.file

int main(int argc, char const *argv[])
{
    MyStruct st;
    st.structFunc("with love from main");

    return 0;
}
