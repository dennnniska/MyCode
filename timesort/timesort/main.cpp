#include <iostream>
#include "read_vector.h"
#include "Timsort.h"
#include<ctime>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	setlocale(LC_ALL, "Russian");
	clock_t start = clock();
	read_vector arr;
	arr.reader();

	

	Timsort sort;
	sort.sort(arr);

	clock_t end = clock();

	std::cout << std::endl << end - start << std::endl;
	int size;
	clock_t start1 = clock();
	std::cin >> size;
	std::vector<int> a(size);
	for (int i = 0; i < size; i++) {
		std::cin >> a[i];
	 }
	
	

	std::sort(a.begin(), a.end());
	clock_t end1 = clock();
	cout << std::endl <<  end1 - start1;
	return 0;
}