#include <iostream>
#include <string>
#include <vector>


/*
    A student database program. 
    The program will ask the user for how many students the user wants to input.
    For each student the program will store the students name, age and grade.
    The program will then print out the average grade of the class and the student with the highest grade.
*/


struct Student{
    std::string name {""};
    int age {0};
    int grade {4};
};

double getMeanGrade(const std::vector<Student>& db){
    double avgGrade {0.0};
    for (auto &&i : db){
        avgGrade += i.grade;
    }

    return avgGrade / db.size();
}

Student getBestStudent(const std::vector<Student>& db){
    // Not optimized for speed eq. not returning index
    // answers explicitly to "who is the best student?"
    Student bestStudent {};
    for (auto &&i : db){
        if (i.grade > bestStudent.grade){
            bestStudent = i;
        }
    }

    return bestStudent;
}


int main(){

    int numberOfStudents {0};
    std::vector<Student> db;

    std::cout << "Give number of students to insert: ";
    std::cin >> numberOfStudents;

    for (size_t i = 0; i < numberOfStudents; i++){
        Student student {};

        std::cout << "Name: ";
        std::cin >> student.name;

        std::cout << "Age: ";
        std::cin >> student.age;

        std::cout << "Grade: ";
        std::cin >> student.grade;

        db.push_back(student);
        std::cout << std::endl;
    }

    std::cout << "Average class grade: " << getMeanGrade(db) << "\n";
    Student bestStudent = getBestStudent(db);
    std::cout << "Best student: " << bestStudent.name << " "
              << "with grade: " << bestStudent.grade << "\n";


    return 0;
}