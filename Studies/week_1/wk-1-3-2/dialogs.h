#ifndef DIALOGS_H
#define DIALOGS_H

#include "structs.h"

int optionsDialog();
bool userDetailsDialog(BankDataBase&);
bool createUserDialog(BankDataBase&);
bool quitDialog();
double withdrawDialog();
double depositDialog();
void loginDialog(BankDataBase&);
std::string accountIdDialog(UserData&);

#endif