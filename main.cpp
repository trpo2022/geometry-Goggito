#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	std::string line;
	
	std::ifstream in("wkt.wkt");
	if(in.is_open())
	{
		while(getline(in, line))
		{
			std::cout << line << std::endl;
		}
	}
	in.close();
	std::cout << "End of programm" << std::endl; 
	return 0;
}
