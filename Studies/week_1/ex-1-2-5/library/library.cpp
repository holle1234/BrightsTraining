#include "library.h"
#include "../utils/utils.h"
#include <iostream>
#include <ostream>


void printBookCreationErrorMsg(){
    std::cout << "Something went wrong while assigning a member\n";
}


bool createBookDialog(Book& book){

    std::string tempString;
    std::cout << "Give book info\n";

    std::cout << "Book title: ";
    std::getline(std::cin, tempString);
    if (!checkNonEmptyString(book.title, tempString)){
        printBookCreationErrorMsg();
        return false;
    }

    std::cout << "Book author: ";
    std::getline(std::cin, tempString);
    if (!checkNonEmptyString(book.author, tempString)){
        printBookCreationErrorMsg();
        return false;
    }

    std::cout << "Book year: ";
    std::getline(std::cin, tempString);
    if (!checkNonEmptyString(book.year, tempString)){
        printBookCreationErrorMsg();
        return false;
    }

    std::cout << "Book ISBN: ";
    std::getline(std::cin, tempString);
    if (!checkNonEmptyString(book.ISBN, tempString)){
        printBookCreationErrorMsg();
        return false;
    }

    std::cout << "Book quantity: ";
    std::getline(std::cin, tempString);

    try{
        int quantity = std::stoi(tempString);
        book.quantity = quantity;
    }
    catch(const std::invalid_argument& e){
        return false;
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const Book& book)
{
    return os << "Book: author: '" << book.author << "' title: '" << book.title << "' year: "
              << book.year << " ISBN: " << book.ISBN << " stock size: " << book.quantity 
              << " loaned books: " << book.nLoanded << "\n";
}


