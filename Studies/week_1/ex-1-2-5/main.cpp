#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include <limits>


struct Library;

struct Book
{
    std::string title;
    std::string author;
    std::string ISBN;
    std::string year;
    int quantity;
};


std::ostream& operator<<(std::ostream& os, const Book& book)
{
    return os << "Book info: " << book.author << " " << book.title << " "
              << book.year << " " << book.ISBN << " " << book.quantity << "\n";
}


int convertToInt(std::string s){
    try{
        return std::stoi(s);
    }
    catch(const std::invalid_argument& e){
        return std::numeric_limits<int>::quiet_NaN();
    }
}


bool safeAssign(std::string& member, std::string& value){
    if (!std::empty(value)){
        member = value;
        return true;
    }
    std::cout << "Something went wrong while assigning a member\n";
    return false;
}


bool addBookDialog(Book& book){

    std::string tempString;
    std::cout << "Give book info\n";

    std::cout << "Book title: ";
    std::getline(std::cin, tempString);
    if (!safeAssign(book.title, tempString)){
        return false;
    }

    std::cout << "Book author: ";
    std::getline(std::cin, tempString);
    if (!safeAssign(book.author, tempString)){
        return false;
    }

    std::cout << "Book year: ";
    std::getline(std::cin, tempString);
    if (!safeAssign(book.year, tempString)){
        return false;
    }

    std::cout << "Book ISBN: ";
    std::getline(std::cin, tempString);
    if (!safeAssign(book.ISBN, tempString)){
        return false;
    }

    std::cout << "Book quantity: ";
    std::getline(std::cin, tempString);

    int quantity = convertToInt(tempString);
    if (quantity == std::numeric_limits<int>::quiet_NaN()){
        return false;
    }else {
        book.quantity = quantity;
    }
    
    return true;
}


struct Library{

    private:
        std::vector<Book> books;
        std::vector<Book> loaned;
    public:
        Book getBookwithISBN(std::string ISBN){
            for (auto &&book : books){
                if (book.ISBN == ISBN){
                    return book;
                }
            }
            Book book;
            return book;
        }

        // add new book to library
        void add(){
            Book newBook;
            if (addBookDialog(newBook)){books.push_back(newBook);}
            std::cout << "Something went wrong adding a book!\n";
        }

        // remove if exists
        void remove(Book book){
            auto it = std::find_if(books.begin(), books.end(),
                                   [&](const Book& b){return b.ISBN == book.ISBN;});
            if (it != books.end()){
                books.erase(it);
            }
        }
        // print book via overloaded cout
        void showBook(Book book){
            std::cout << book;
        }

        // print all books
        void showBooks(){
            for (auto &&book : books){
                showBook(book);
            }
        }

        void loan(Book book){
            auto it = std::find_if(loaned.begin(), loaned.end(),
                      [&](const Book& b){return b.ISBN == book.ISBN;});

            // not in loaned, add one with count 1
            if (it == loaned.end()){
                book.quantity = 1;
                loaned.push_back(book);
            }
            // one loaned already add count
            (*it).quantity += 1;
        }

        // returns if book is in loaned vector
        bool isLoaned(const Book& book){
            auto it = std::find_if(loaned.begin(), loaned.end(),
                        [&](const Book& b){return b.ISBN == book.ISBN;});
            
            return (it != loaned.end());
        }
};




/*
Exercise:  Book Management System

You have been tasked with developing a Book Management System for a library.
The system should allow users to manage books in the library
Books in the library have the following information.
Title, Author, ISBN, Year, Quantity.
The information will be stored with proper data types.
There should be a function to display a book, add a book and remove a book,
see if the book has been loaned or not. 

*/

int main(int argc, char const *argv[])
{

    Library library;
    std::string cont;

    while (true){

        library.add();
        std::cout << "Continue? (y/n): ";
        std::cin >> cont;
        std::cin.ignore(1);
        if(cont == "n"){
            break;
        }
    }

    library.showBooks();
    


    return 0;
}

