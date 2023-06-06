#include <iostream>
#include <string>



//Program to reverse string manually without using library functions


std::string reverseString(const std::string& st){

    std::string reversedString {st};
    int index {0};

    for (int i = st.length() - 1; i >= 0; i--)
    {
        reversedString[index] = st[i];
        index++;
    }
    
    return reversedString;
}


int main(){

    std::string inputString {};
    std::cout << "Welcome to reverse string program" << "\n"
              << "Give string to reverse: ";

    std::cin >> inputString;
    std::cout << "Your string reversed is: "
              << reverseString(inputString) << "\n";
    return 0;
}