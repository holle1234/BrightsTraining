#include "source/exam.h"
#include <vector>



int main(int argc, char const *argv[])
{
    Dealer d;
    d.init_deck();

    Player& player = d.join_game("Simo");
    d.deal_next();
    std::cout << player.cards;

    return 0;
}
