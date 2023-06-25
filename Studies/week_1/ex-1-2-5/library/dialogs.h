#if !defined(DIALOG)
#define DIALOG


#include "library.h"


const std::array<std::string, 6> mainMenuOptions {"View",
                                                  "Add",
                                                  "Remove",
                                                  "Loan bok",
                                                  "Return book",
                                                  "Quit"};


int mainMenuDialog();

void viewBookDialog(Library &library);

void removeBookDialog(Library &library);

void addBooksDialog(Library &library);

void loanBookDialog(Library &library);

void returnBookDialog(Library &library);

bool quitBookDialog(Library &library);

#endif // DIALOG
