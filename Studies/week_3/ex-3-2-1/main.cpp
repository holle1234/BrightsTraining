#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include <ostream>


// easier to work with complex data
using CityPair = std::pair<std::string, int>;
using CityVector = std::vector<CityPair>;


// Distance table
const double table[5][5]
                    //Panama New York Amsterdam Helsinki Durban
                    {{0,	 4.460,	   8.440,	9.240,	12.950}, // Panama 
                    {4.460,	 0,	       5.700,	6.620,	12.700}, // New York
                    {8.440,	 5.700,	   0,	    1.520,	9.760},  // Amsterdam
                    {9.240,	 6.620,	   1.520,	0,	    10.480}, // Helsinki
                    {12.950, 12.700,   9.760,	10.480,	0}};     // Durban



// Overload of cout to ease printing
std::ostream& operator<<(std::ostream& os, const CityVector cv){
    for (auto &&i : cv)
    {
        os << i.first << " ";        
    }
    return os;
}

// Total distance of specific route
double total_distance(CityVector cities){

    double totalSum {0.0};
    CityPair start_point {cities[0]};

    for (auto &&city : cities)
    {
        totalSum += (table[start_point.second][city.second]);
        start_point = city;
    }
    return totalSum;
    
}


// Very hard to follow common recursive backtracking permutator
void permute(CityVector& cities, int start, int end, std::vector<CityVector>& dest){   

    // Base case
    if (start == end){
        dest.push_back(cities);
    }

    else {
        // Permutations made
        for (int i = start; i <= end; i++) {

            // swap first
            std::swap(cities[start], cities[i]);

            // Recursion called
            permute(cities, start + 1, end, dest);

             // swap second
            std::swap(cities[start], cities[i]);
    
        } 
    }
}


/* 
Get permutations of vector of string.
Will return all possible permutations if no query is present.
Otherwise returns permutations where query is at the first spot.*/
void permutate_for(CityVector& cities, std::string query=""){

    int end = cities.size() -1;
    int begin = 0;

    // if query is present put query at first position
    if(!std::empty(query)){
        auto it = std::find_if(cities.begin(), cities.end(),
                    [&](const CityPair& s){return s.first == query;});

        // check if anything was found           
        if (it == cities.end()){
            throw std::invalid_argument("Query '" + query + "' not in the array\n");

        }else{
            std::iter_swap(cities.begin(), it);
            begin = 1;
        }
    }

    std::vector<CityVector> dest;
    permute(cities, begin, end, dest);

    // Find the shortest path and save it here
    std::pair<CityVector, double> best {dest.front(), -1};

    for (auto &&cityVector : dest){
        double totalDist = total_distance(cityVector);

        if (best.second < 0 || totalDist < best.second){
            std::cout << cityVector << " dist: " << totalDist << "\n";
            best = {cityVector, totalDist};
        }
    }

    std::cout << "Best travel order is: " << best.first 
              << " with dist: " << best.second << " thousand miles\n";
    
}


/* 
Find shortest route to visit all harbors.
You can change the starting harbor by setting 'permutate_for(a,b)' b argument
Does check if the b argument is int the table.
If no b argument is supplied, the shortest route between all permutations is returned.


SAMPLE PRINT:

Check all routes
New York Amsterdam Helsinki Durban Panama  dist: 30.65
New York Amsterdam Helsinki Panama Durban  dist: 29.41
New York Panama Helsinki Amsterdam Durban  dist: 24.98
New York Panama Amsterdam Helsinki Durban  dist: 24.9
Helsinki Amsterdam New York Panama Durban  dist: 24.63
Durban Amsterdam Helsinki New York Panama  dist: 22.36
Durban Helsinki Amsterdam New York Panama  dist: 22.16
Best travel order is: Durban Helsinki Amsterdam New York Panama  with dist: 22.16 thousand miles

Check Panama
Panama Amsterdam Helsinki Durban New York  dist: 33.14
Panama Amsterdam Helsinki New York Durban  dist: 29.28
Panama Helsinki Amsterdam New York Durban  dist: 29.16
Panama New York Helsinki Amsterdam Durban  dist: 22.36
Panama New York Amsterdam Helsinki Durban  dist: 22.16

*/



int main(int argc, char const *argv[])
{
    CityVector cities {{"New York", 1}, {"Amsterdam", 2}, {"Helsinki", 3}, {"Durban", 4}, {"Panama", 0}};
    std::cout << "Check all routes\n";
    permutate_for(cities);
    std::cout << "\nCheck Panama\n";
    permutate_for(cities, "Panama");
}
