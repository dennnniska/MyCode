#include"queue.h"
#include <queue>
#pragma once
class BFS
{
public:
	int BFS_cp(int **matr, int kol);
private:
	int count;
	int* distance;
	int* prevTop;
	std::queue<int> Q;
};

