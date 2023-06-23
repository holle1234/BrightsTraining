#include "library/dialogs.h"
#include "library/library.h"
#include <iostream>

/*
Exercise:  Book Management System

You have been tasked with developing a Book Management System for a library.
The system should allow users to manage books in the library.
Books in the library have the following information.
Title, Author, ISBN, Year, Quantity.
The information will be stored with proper data types.
There should be a function to display a book, add a book and remove a book,
see if the book has been loaned or not. 

*/

int main(int argc, char const *argv[])
{

/* 
View",
                                                  "Add",
                                                  "Remove",
                                                  "Loan bok",
                                                  "Return book",
                                                  "Quit"};

 */

    Library library;
    while (true){
        int option = mainMenuDialog();

        switch (option){
        case 0: {
            viewBookDialog(library);
            break;
        }
        case 1: {
            addBooksDialog(library);
            break;}
        case 2: {
            removeBookDialog(library);
            break;}

        case 3: {
            loanBookDialog(library);
            break;}

        case 4: {
            returnBookDialog(library);
            break;}

        case 5: {
            bool quit = quitBookDialog(library);
            if (quit){exit(0);}
            else break;
        }
        default:
            return 0;
        }
    }

    return 0;
}

