#include "libgeom/geometry.h"

#include <cstring>
#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

const double Pi = 3.1415;

void Circle(int counter, int string, std::string storage[]){
    
    double r, S, P;
    std::size_t found, lfound, rfound, rezfound;
    std::string x = storage[string], str_r = "", numbers = "1234567890";

    std::cout << "\n\n " << counter << ". " << x
              << std::endl; // 1 output string

    found = x.find(",");
    if (found != std::string::npos) {
        lfound = x.find_first_of(numbers, found);
        rfound = x.find_last_of(numbers);
        rezfound = rfound - lfound + 1;
        
        str_r.append(x, lfound, rezfound);
        r = atof(str_r.c_str());
        S = Pi * pow(r, 2);
        printf("    S = %f", S); // 2 output string
        P = 2 * Pi * r;
        printf("\n    P = %f", P); // 3 output string
    } else {
        printf("Error ");
    }
}

void Triangle(int counter, int string, std::string storage[]){
    counter++;
    std::cout << "\n\n " << counter << ". " << storage[string] << std::endl;
}
