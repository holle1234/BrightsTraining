#include "vector/vector.h"
#include <iostream>


int main(int argc, char const *argv[])
{
    vector3D::Vector vec = vector3D::Vector::create(1,2,3);
    std::cout << vec;
    auto vec2 = vec + vec;
    auto vec3 = vec - vec;
    vec2 -= vec2;
    vec += vec;

    return 0;
}
