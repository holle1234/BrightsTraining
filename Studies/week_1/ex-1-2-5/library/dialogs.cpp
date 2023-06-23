#include "../utils/utils.h"
#include "library.h"
#include <iostream>
#include "dialogs.h"


int mainMenuDialog(){
    int option = menuPrompt(mainMenuOptions.begin(),
                            mainMenuOptions.end());
    if (option == -1){
        std::cout << "Invalid option, please try again\n";
    }
    return option;
}

void viewBookDialog(Library& library){
    auto books = library.getBooks();
    printOptions(books.begin(), books.end());
}


void removeBookDialog(Library& library){
    auto books = library.getBooks();
    if (books.size() < 1){
        std::cout << "Nothing to show. No entries in the DataBase\n";
        return;
    }

    int option = menuPrompt(books.begin(),
                            books.end());
                            
    // if the choice was valid
    if (option > -1){
        library.remove(books[option]);
    }
    
}

void addBooksDialog(Library& library){
    std::string cont {"y"};

    while (true){

        Book newBook;
        if (!createBookDialog(newBook)){
            std::cout << "Invalid argument! Aborting..\n";
        }
        else if(library.bookExist(newBook)){
            std::cout << "Book already exists!\n";
        }
        library.add(newBook);
        std::cout << "Continue? (y/n): ";
        std::getline(std::cin, cont);
        if(cont == "n"){
            break;
        }
    }
}

void loanBookDialog(Library& library){
    auto books = library.getBooks();
    if (books.size() < 1){
        std::cout << "Nothing to show. No entries in the DataBase\n";
        return;
    }

    int option = menuPrompt(books.begin(),
                            books.end());

    // if the choice was valid
    if (option > -1){
        library.loanBook(books[option]);
    }
    
}


void returnBookDialog(Library& library){
    auto books = library.getBooks();

    if (books.size() < 1){
        std::cout << "Nothing to show. No entries in the DataBase\n";
        std::cout << "Guess this is yours to keep :D\n";
        return;
    }

    int option = menuPrompt(books.begin(),
                            books.end());
                            
    // if the choice was valid
    if (option > -1){
        library.returnBook(books[option]);
    }

}

bool quitBookDialog(Library& library){
    std::string cont {"n"};
    std::cout << "Type y to confirm: ";

    std::getline(std::cin, cont);
    return cont == "y";

}