#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <iomanip>


// Ex 1.
std::string reverse_string(std::string& input, int pos=-1){
    // avoid making copies of this string by making just one at the first iteration
    if (pos < 0){
        std::string strcopy = input;
        return reverse_string(strcopy, pos + 1);
    }
    
    if (pos != input.size() / 2){
        std::swap(input[pos], input[input.size() - pos - 1]);
        reverse_string(input, pos+1);
    }

    return input;
}

// Ex 2.
int gcd(int a, int b){
    if (b == 0){return a;}
    gcd(b, a % b);
}

// Ex.3

int power(int a, int b){
    if (b == 0){
        return 1;
    }
    return a * power(a, b - 1);
}

// Ex.4
using pile = std::vector<int>;
using allpiles = std::vector<pile>;


// Compute tower of hanoi on vectors of int
void tower_of_hanoi(int peg, pile& source, pile& dest, pile& aux){

    if (peg == 1){
        dest.push_back(source.back());
        source.pop_back();
        return;

    }else {
        tower_of_hanoi(peg - 1, source, aux, dest);
        dest.push_back(source.back());
        source.pop_back();
        tower_of_hanoi(peg - 1, aux, dest, source);
    }
}

/* 
Print tower of hanoi in human readable form:

1234567     -------
------- --> 1234567
-------     -------

 */
void print_hanoi(allpiles& piles){
    // find longest vector and set print width
    auto it = std::max_element(piles.begin(), piles.end(),
                               [](const auto& a, const auto& b) {
                                    return a.size() < b.size();
                               });
    int w = it->size();

    std::stringstream ss;
    for (auto &&i : piles){
        std::copy(i.begin(), i.end(), std::ostream_iterator<int>(ss, ""));
        std::cout << std::setw(w) << std::setfill('-') << ss.str() << "\n";
        ss.str("");
        ss.clear();
    }
}


int main(int argc, char const *argv[])
{
    // Ex 1.
    std::string to_reverse {"lol this is wowe"};
    std::string in_reverse = reverse_string(to_reverse);
    std::cout << to_reverse << "in reverse is :" << in_reverse << "\n";

    // Ex 2.
    std::cout << "Greatest common divisor for (25, 40) is: " << gcd(25, 40) << "\n";

    // Ex. 3
    std::cout << "Power of 2 to 5 should be 32: function says: " << power(2, 5) << "\n";

    // Ex. 4
    pile a {1,2,3,4,5,6,7};
    pile b, c;

    // print start position
    std::cout << "compute tower of hanoi:\n\n";
    allpiles hanoi {a, b, c};
    print_hanoi(hanoi);
    std::cout << "\n";

    // compute hanoi
    tower_of_hanoi(7, a, b, c);

    // print end position
    hanoi = {a, b, c};
    print_hanoi(hanoi);
    std::cout << "\n";

    return 0;
}
