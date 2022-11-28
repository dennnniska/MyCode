#include <string>
#include "read.h"
void read::reads() {
	fin.open("../input.txt");
	fin >> line;
	fin.close();
}

std::string read::get_line() {
	return line;
}