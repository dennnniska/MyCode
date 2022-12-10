#include"reader.h"
#include"ver.h"
#include"BFS.h"
#include"build.h"
#include"sort.h"
#include"OST.h"
#include<iostream>
#include"write.h"
#pragma once
class start
{
public:
	void begin();
	~start();
private:
	reader read;
	int** matr;
	int kol_reb;
	int kol_ver;
	std::string s;
	std::string* ver;
	build bl;
	ver_sm *vera;
	sort sort_;
	OST tree;
	int ans;
	ver_sm* ans_ver;
	int size;
	write _write;
	int comp;
	BFS compBFS;
};

