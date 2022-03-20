#include "libgeom/geometry.h"

#include <cstring>
#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

int main()
{
    int counter = 0;
    int storage_size = 100;
    std::string storage[storage_size];
    std::string line;
    std::string file_name;
    std::cout << "\n The program accepts format files as input .wkt!";
    std::cout << "\n Enter the file name: ";
    std::cin  >> file_name;
    std::ifstream in (file_name);
    if (in.is_open()) {
        while (getline(in, line)) {
            storage[counter] = line;
            counter++;
        }
    } else {
        printf(" !Open File Error\n !File not found");
    }

    int verif_counter = 0;
    int order_counter = 0;
    for (int counter_f = 0; counter_f < counter; counter_f++) {
        std::size_t found;
        found = storage[counter_f].find("circle");
        if (found != std::string::npos) {
            verif_counter++;
            order_counter++;
            Circle(order_counter, counter_f, storage);
        }

        found = storage[counter_f].find("triangle");
        if (found != std::string::npos) {
            verif_counter++;
            order_counter++;
            Triangle(order_counter, counter_f, storage);
        }

        if (verif_counter == 0) {
            printf("\n\n #Error in %d line, «circle» , «triangle»  or "
                   "«polygon»  not found ",
                   counter_f + 1);
            std::cout << "\n " << counter_f + 1 << ". " << storage[counter_f]
                      << std::endl;
        }
        verif_counter = 0;
    }

    in.close();
    std::cout << "\n\n End of programm\n" << std::endl;
    return 0;
}
