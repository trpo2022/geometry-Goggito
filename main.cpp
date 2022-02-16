#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	
	int counter = 0;
	int storage_size = 500;
	string storage[storage_size];
	
	std::string line;
	std::ifstream in("wkt.wkt");
	
	if (in.is_open())
	{
		while(getline(in, line))
		{
			storage[counter] = line;
			counter++;
		}
	}
	
	in.close();
	std::cout << "End of programm" << std::endl; 
	return 0;
}
