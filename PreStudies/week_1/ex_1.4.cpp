#include <iostream>
#include <math.h>

using namespace std;

double circleArea(double pi, double r){
    return pi * pow(r, 2);
}

double circleCircumference(double pi, double r){
    return 2 * pi * r;
}

int main(){
    double radius;
    double area, circumference;
    const double pi = 3.141;

    while (radius != -1){
        cout << "Give circle radius (quit = -1): ";
        cin >> radius;
        if(radius == -1){break;}

        area = circleArea(pi, radius);
        circumference = circleCircumference(pi, radius);
        cout << endl << "area: " << area
                     << " circumference: " << circumference << endl;

    }
    
    
    

    return 0;
}