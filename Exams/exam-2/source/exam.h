#if !defined(EXAM)
#define EXAM


#include <type_traits>
#include <vector>
#include <ostream>
#include <algorithm>
#include <random>
#include <string>
#include <iostream>


namespace randomness
{
static auto rd = std::random_device {}; 
static auto rng = std::default_random_engine { rd() };   

template<typename it>
void shuffle(it begin, it end){
    std::shuffle(begin, end, rng);
}

} // namespace randomness



class PlayingCard
{

private:
    unsigned int _value {0};
    unsigned int _suit {0};

public:

    PlayingCard(unsigned int value, unsigned int suit) : _value(value), _suit(suit) {}
    PlayingCard() = delete;
    friend std::ostream &operator<<(std::ostream &os, const PlayingCard &card);

    unsigned int value() const {
        return _value;
    }

    unsigned int suit() const {
        return _suit;
    }

};


class Deck

{
public:
    using storage_type = std::vector<PlayingCard>;
    using value_type = PlayingCard;
    using reference	= PlayingCard&;
    using const_reference = const PlayingCard&;	
    using iterator = typename storage_type::iterator;
    using const_iterator = typename storage_type::const_iterator;
    using difference_type = typename storage_type::difference_type;
    using size_type = typename storage_type::size_type;

    friend std::ostream &operator<<(std::ostream &os, const Deck &cont);

private:
    storage_type data;
public:

    Deck() = default;
    ~Deck() {};

    void push_back(PlayingCard card){
        data.push_back(card);
    }

    const PlayingCard& top(){
        return data.back();
    }

    const PlayingCard& bottom(){
        return data.front();
    }

    PlayingCard draw(){
        auto top_card = data.back();
        data.pop_back();
        return top_card;
    };

    void shuffle(){
        randomness::shuffle(data.begin(), data.end());
    }

    void clear(){
        data.clear();
    }

    iterator begin(){
        return data.begin();
    }

    iterator end(){
        return data.end();
    }

    const_iterator begin() const{
        return data.begin();
    }

    const_iterator end() const{
        return data.end();
    }

    size_t size() const{
        return data.size();
    }
};




class Player
{
public:
    std::string name;
    Deck cards;

    Player(std::string name) : name(name){}
    ~Player() {}

    void deal(PlayingCard card){
        cards.push_back(card);
    }
};


class Rules
{

public:
    Rules() {}
    ~Rules() = default;

    unsigned int count(Player& player){
        unsigned int tally {0};
        unsigned int ace_count {0};

        for (auto &&card : player.cards){
            tally += card.value();
        }

        if (tally > 21){
            tally -= (ace_count * 13);
        }

        return tally;
    }
};


class Dealer : public Rules
{
private:
    Deck cards;
    std::vector<Player> players;
    unsigned int player_index {0};

public:

    Dealer(){}
    ~Dealer(){}

    Player& join_game(std::string name){
        Player player {name};
        players.push_back(std::move(player));
        return players.back();
    }

    void init_deck(){
        cards.clear();
        for (unsigned int suit = 1; suit < 5; suit++){
            for (unsigned int value = 2; value < 15; value++){
                PlayingCard card {value, suit};
                cards.push_back(card);
            }
        }
        cards.shuffle();
    }

    void deal_next(){

        if (player_index > players.size() - 1){
            player_index = 0;
        }
        Player& next_player = players[player_index];
        next_player.deal(std::move(cards.draw()));
    }
};


class Game{

public:

    Player house {"house"};
    Dealer dealer;

    Game(){

    }

};


#endif // EXAM
