#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <iomanip>
#include <sstream>


struct Food{
    std::string name;
    double price;
    std::vector<std::string> ingredients;
};


struct Menu{
    std::vector<Food> foods; 
};


struct Order{
    std::vector<Food> orders;
    double totalPrice {0.0};
};



// overload order for cout
std::ostream &operator<<(std::ostream &os, const Order &o) {
    std::string out {"\nOrder contains:\n"};
    for (auto &&food : o.orders){
        out += (food.name + "\n");
    }

    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << o.totalPrice;
    out += ("Total price: " + stream.str()+ "\n");
    return os << out;
}

// overload menu for cout
std::ostream &operator<<(std::ostream &os, const Menu &m) {
    std::string out {"\nMenu contains:\n"};
    for (auto &&food : m.foods){
        out += (food.name + "\n");
    }
    out += + "\n";
    return os << out;
}


void addFoodToMenu(const Food& food, Menu& menu){
    menu.foods.push_back(food);
}

void addFoodToOrder(const Food& food, Order& order){
    order.orders.push_back(food);
    order.totalPrice += food.price;
}


Food createFood(){
    Food dish;
    std::cout << "\nCreating a new dish!\n";

    std::cout << "Give dish name: ";
    std::cin >> dish.name;

    std::cout << "Give price: ";
    std::cin >> dish.price;

    std::cout << "Give ingredients to prepare dish\n";

    std::string continueLoop;
    while (continueLoop != "n")
    {
        // will jump if not ignored
        std::cin.ignore(1, '\n');
        std::cout << "Give next ingredient: ";
        std::string newIngredient;
        std::getline(std::cin, newIngredient);
        dish.ingredients.push_back(newIngredient);
        
        std::cout << "Continue? (y/n): ";
        std::cin >> continueLoop;
    }
    
    return dish;
}


int main(int argc, char const *argv[])
{
    Menu menu;
    Food food {createFood()};
    addFoodToMenu(food, menu);
    addFoodToMenu(food, menu);
    std::cout << menu;

    Order order;
    addFoodToOrder(food, order);
    addFoodToOrder(food, order);
    addFoodToOrder(food, order);

    std::cout << order;

    std::cout << "Pick from the menu: ";
    // read in orders in loop
    // add to order






    return 0;
}
