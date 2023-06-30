#include "csv.h"


namespace csv {
    
void pretty_print(csv::StringRow row, int max_size=10){

    std::string res (max_size, ' ');
    for (size_t i = 0; i < row.size(); i++){
        // all are max_size or less characters
        std::string value = row[i].substr(0, max_size);
        res.replace((max_size - value.size()) / 2, value.size(), value);
        std::cout << "|" << res <<  "|";
        res.assign(max_size, ' ');
    }
}
};