#include<fstream>
#pragma once
class reader
{
private:
	std::string s;
	std::ifstream fin;
	int** matr;
	int kol_ver;
	int kol_rebr;
public:
	void read_file();
	~reader();
	int** getMatr();
	int getKol_ver();
	int getKol_rebr();
	std::string getSt();
};

