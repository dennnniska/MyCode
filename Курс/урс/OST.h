#include"ver.h"
#include<iostream>
#pragma once
class OST
{
private:
	int ans;
	ver_sm* ans_ver;
	ver_sm* bl_ver;
	int size_ver;
	int size;
	int *comp;
public:
	void biuld_OST(ver_sm *vera, int kol_ver, int kol_reb);
	~OST();
	int get_ans();
	ver_sm* get_ans_ver();
	int get_size();
};

