#include<iostream>
#include"ver.h"
#pragma once
class build
{
private:
	std::string *ver;
	std::string bl_ver;
	ver_sm *vera;
	int p;
public:
	ver_sm* build_reb(int kol_reb, int kol_ver, int **matr);
	std::string* build_ver(std::string s, int kol_ver);
};

