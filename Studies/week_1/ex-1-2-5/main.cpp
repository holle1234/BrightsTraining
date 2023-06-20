#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


struct Book
{
    std::string title;
    std::string author;
    std::string ISBN;
    std::string year;
    int quantity;
};


std::ostream& std::operator<<(ostream& os, const Book& book)
{
    return os << "book";
}


struct Library
{
    private:
        std::vector<Book> books;
        std::vector<Book> loaned;
    public:
        // add new book to library
        void add(Book book){
            books.push_back(book);
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
        void show(Book book){
            std::cout << book;
        }

        Book loan(Book book){
            auto it = std::find_if(loaned.begin(), loaned.end(),
                      [&](const Book& b){return b.ISBN == book.ISBN;});
            if (it == loaned.end()){
                loaned.push_back(book);
            }
        }

        // returns if book is in loaned vector
        bool isLoaned(Book book){
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
    /* code */
    return 0;
}

