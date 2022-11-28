#include <fstream>
#include <iostream>
#include <string>
#pragma once
class read
{
private:
	std::ifstream fin;
	std::string line;
public:
	void reads();
	std::string get_line();
	
};

