#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <limits>

#include "src/utils.h"



enum class MenuOptions{
    mainMenu,
    addMenu,
    viewMenu,
    addOrder,
    viewOrder,
    checkout,
    quit,

};


MenuOptions mainMenu(){
    std::vector<std::string> messages {
        "1. Add to Menu",
        "2. View Menu",
        "3. Add to Order",
        "4. View Order",
        "5. Checkout",
        "6. Quit"
    };

    std::copy(messages.begin(), messages.end(),
                std::ostream_iterator<std::string>(std::cout, "\n"));
    std::cout << "Your wish is my command: ";

    int action {0};
    std::cin >> action;
    system("clear");
    return MenuOptions{action};
}

bool continuePrompt(const std::string& msg = "Continue?"){
    char key {' '};
    std::cout << (msg + " (y/n): ");
    std::cin >> key;
    system("clear");
    return key == 'y';
}


int main(int argc, char const *argv[])
{

    Menu menu;
    Order order;

    MenuOptions action {MenuOptions::mainMenu};
    system("clear");

    while (true)
    {
        switch (action)
        {
        case MenuOptions::mainMenu:{
            action = mainMenu();
            break;
        }
        case MenuOptions::addMenu :{
            updateMenu(menu);
            action = MenuOptions::mainMenu;
            break;
        }
        case MenuOptions::viewMenu:{
            std::cout << menu;
            continuePrompt();
            action = MenuOptions::mainMenu;
            break;
        }
        case MenuOptions::addOrder:{
            updateOrder(menu, order);
            action = MenuOptions::mainMenu;
            break;
        }
        case MenuOptions::viewOrder:{
            std::cout << order;
            action = MenuOptions::mainMenu;
            continuePrompt();
            break;
        }
        case MenuOptions::checkout:{
            std::cout << order;
            action = MenuOptions::mainMenu;
            if(continuePrompt("Checkout?")){
                order = {};
            };
            break;
        }        
        case MenuOptions::quit:{
            if(continuePrompt("Quit?")){return 0;}
            break;
        }
        
        default: {return 0;}
        }
        
    }

    return 0;
}
