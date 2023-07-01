#if !defined(UTILS)
#define UTILS


#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <limits>


struct Food{

    double price;
    std::string name;
    std::vector<std::string> ingredients;

    // overload == with Food for count
    bool operator==(const Food& another) {
        return name == another.name;
    }

    // overload == with string for find
    bool operator==(const std::string& s) {
        return (name == s);
    }

    // overload < with food for sort
    bool operator<(const Food& another) {
        return name < another.name;
    }

};


struct Menu{
    std::vector<Food> foods; 
};


struct Order{
    std::vector<Food> orders;
    double totalPrice {0.0};
};

// cout overloads
std::ostream &operator<<(std::ostream&, const Order&);
std::ostream &operator<<(std::ostream&, const Menu&);

// helper functions
void addFoodToMenu(const Food&, Menu&);
void addFoodToOrder(const Food&, Order&);
void updateMenu(Menu&);
void updateOrder(Menu&, Order&);
Food createFood();


#endif // UTILS

