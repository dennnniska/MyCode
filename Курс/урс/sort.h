#include"ver.h"
#include<iostream>
#pragma once
class sort
{
private:
	void sortMR(ver_sm* mas, int start, int end);
	int mid;
	void build(ver_sm* mas, int start, int mid, int end);
public:
	void sortMR(ver_sm* mas, int kol);
};

