#include "geometry.h"

#include <cstring>
#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

const double Pi = 3.1415;

Point Point_analysis(int string, int& lfound, std::string storage[])
{
    Point P;
    std::size_t found, l_number, r_number;
    std::string str = storage[string], str_r = "", numbers = "1234567890.-";
    found = str.find(")");
    if (found != std::string::npos) {
        // X analysis
        l_number = str.find_first_of(numbers, lfound);
        for (r_number = l_number;
             numbers.find(str[r_number]) != std::string::npos;
             r_number++)
            ;
        std::string str_x;
        str_x.append(str, l_number, r_number);
        P.x = atof(str_x.c_str());

        // Y analysis
        r_number = str.find_last_of(numbers, str.find_first_of(",", lfound));
        for (l_number = r_number;
             numbers.find(str[l_number]) != std::string::npos;
             l_number--)
            ;
        std::string str_y;
        str_y.append(str, l_number, r_number);
        P.y = atof(str_y.c_str());

        // New left border
        lfound = str.find_first_of(",", lfound) + 1;
    } else {
        printf("Error ");
    }
    return P;
}

Circle Circle_analysis(int order, int string, std::string storage[])
{
    Circle C;
    std::size_t found, r_number, l_number, rezfound;
    std::string x = storage[string], str_r = "", numbers = "1234567890";

    C.Order = order;

    found = x.find(",");
    if (found != std::string::npos) {
        l_number = x.find_first_of(numbers, found);
        r_number = x.find_last_of(numbers);
        rezfound = r_number - l_number + 1;
        str_r.append(x, l_number, rezfound);

        C.r = atof(str_r.c_str());

        C.S = Pi * pow(C.r, 2);

        C.P = 2 * Pi * C.r;

    } else {
        printf("Error ");
    }

    int lfound = storage[string].find("(");
    C.Center = Point_analysis(string, lfound, storage);
    return C;
}

Triangle Triangle_analysis(int order, int string, std::string storage[])
{
    Triangle T;

    T.Order = order;

    int lfound = storage[string].find("(");
    T.A = Point_analysis(string, lfound, storage);
    T.B = Point_analysis(string, lfound, storage);
    T.C = Point_analysis(string, lfound, storage);
    T.End = Point_analysis(string, lfound, storage);

    T.S = 0.5
            * abs((T.A.x - T.C.x) * (T.B.y - T.C.y)
                  - (T.B.x - T.C.x) * (T.A.y - T.C.y));

    float AB = sqrt(pow(T.B.x - T.A.x, 2) + pow(T.B.y - T.A.y, 2));
    float BC = sqrt(pow(T.C.x - T.B.x, 2) + pow(T.C.y - T.B.y, 2));
    float CA = sqrt(pow(T.A.x - T.C.x, 2) + pow(T.A.y - T.C.y, 2));
    T.P = AB + BC + CA;
    return T;
}


void Circle_intersec(Circle C, Circle CM[], Triangle TM[]){
    
}

void Triangle_intersec(Triangle T, Circle CM[], Triangle TM[]){

}


void Circle_print(Circle C, std::string storage[])
{
    std::cout << "\n " << C.Order << ". " << storage[C.Order - 1]
              << "\n      perimeter = " << C.P << "\n      area = " << C.S
              << std::endl;
}

void Triangle_print(Triangle T, std::string storage[])
{
    std::cout << "\n " << T.Order << ". " << storage[T.Order - 1]
              << "\n      perimeter = " << T.P << "\n      area = " << T.S
              << std::endl;
}