#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <random>


using StudentVector = std::vector<std::string>;


StudentVector getReviewees(const StudentVector& students){
    std::vector<std::string> studentToReview;
    for (size_t i = 0; i < students.size() - 1; i++)
    {
        studentToReview.push_back(students[i + 1]);
    }
    studentToReview.push_back(students[0]);
    return studentToReview;
}


int main(int argc, char const *argv[])
{
    
    StudentVector students {
        "heidi",
        "oskar",
        "karri",
        "ville",
        "elisa",
        "kirsi",
        "mikko",
        "anna"
    };

    // rand gen
    std::random_device rd;
    std::mt19937 g(rd());

    // shuffle students
    std::shuffle(students.begin(), students.end(), g);

    // pair adjacent students and the last one with the first
    StudentVector studentToReview {getReviewees(students)};

    // print data
    for (size_t i = 0; i < students.size(); i++)
    {
        std::cout << students[i] << " reviews " << studentToReview[i] << "\n";
    }

    return 0;
}

