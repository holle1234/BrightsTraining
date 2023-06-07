#ifndef DATABASE_H
#define DATABASE_H


#include <vector>
#include "userdata.h"


struct BankDataBase{
    private:
        std::vector<UserData> db;

        // returns a user id if found -1 otherwise
        int _findUserId(int userId){
            return 0;
        }
        // creates a new user id
        int _createUserId(int userId){
            return 0;
        }

    public:
        UserData createUser(){
            UserData user {};
            return user;
        }

        UserData getUser(int userId){
            if (_findUserId(userId) != 0){
                
            }
            

            UserData user {};
            return user;
        }

};


#endif