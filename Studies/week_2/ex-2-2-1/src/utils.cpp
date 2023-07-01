#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <limits>

#include "utils.h"



void addFoodToMenu(const Food& food, Menu& menu){
    menu.foods.push_back(food);
}

void addFoodToOrder(const Food& food, Order& order){
    order.orders.push_back(food);
    order.totalPrice += food.price;
}


Food createFood(){
    Food dish;
    std::cout << "Creating a new dish!\n";

    std::cout << "Give dish name: ";
    std::cin >> dish.name;

    std::cout << "Give price: ";
    std::cin >> dish.price;

    std::cout << "\nGive ingredients to prepare dish exit with 'q'\n";

    while (true)
    {
        std::string newIngredient;
        std::cout << "Give next ingredient: ";
        std::getline(std::cin, newIngredient);

        if (newIngredient == "q"){break;}
        else dish.ingredients.push_back(newIngredient);
    }
    
    system("clear");
    return dish;
}

void updateMenu(Menu& menu){

    std::string loopCondition {""};
    while (loopCondition != "n")
    {
        std::cout << menu;
        Food food {createFood()};
        addFoodToMenu(food, menu);
        std::cout << "Add new dish? (y/n): ";
        std::getline(std::cin, loopCondition);
        system("clear");
    }
}

void updateOrder(Menu& menu, Order& order){
    std::string loopCondition {""};

    std::cout << menu;
    std::cout << "May I take your order please?\nType 'q' to quit\n\n";

    std::cin.ignore(1, '\n');
    while (loopCondition != "q")
    {
        std::cout << "Add dish to order by name: ";
        std::getline(std::cin, loopCondition);

        auto& menuItems {menu.foods};
        // use food == string overload to find a match
        auto results {std::find(menuItems.begin(),
                                menuItems.end(),
                                loopCondition)};

        // if input matches a menu item add it to the order
        if (results != menuItems.end()){
            addFoodToOrder(*results, order);
        }
    }
    system("clear");
}


// overload cout << Order for ease printing
std::ostream &operator<<(std::ostream &os, const Order &o) {

    // calculate occurances from a sorted vector
    // print out count of unique elements

    auto ordersCopy = o.orders;
    std::sort(ordersCopy.begin(), ordersCopy.end());
    auto it = std::unique(ordersCopy.begin(), ordersCopy.end());
    ordersCopy.erase(it, ordersCopy.end());

    std::string out {"\nOrder contains:\n\n"};


    for (auto &&food : ordersCopy){
        int objCount = std::count_if(o.orders.begin(),
                                     o.orders.end(),
                                    [&](const Food& f) {return food == f;});


        out += ("* " + std::to_string(objCount) + " pcs " + food.name + "\n");
    }

    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << o.totalPrice;
    out += ("\nTotal price: " + stream.str()+ "e\n");
    return os << out;
}

// overload Menu for cout
std::ostream &operator<<(std::ostream &os, const Menu &m) {
    std::string out {"Menu contains:\n\n"};

    if (m.foods.size() == 0){
        out += "*\n";
    }

    std::stringstream stream;
    for (auto &&food : m.foods){

        // round double for pretty printing
        stream << std::fixed << std::setprecision(2) << food.price;
        stream.clear();

        std::string strPrice {stream.str()};
        out += ("* " + food.name + "\t\t" + strPrice + "e\n");
    }
    out += + "\n";
    return os << out;
}


