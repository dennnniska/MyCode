#include <iostream>
#include <string>
#include "reader.h"
reader::~reader() {
	for (int i = 0; i < kol_ver; i++) {
		delete[] matr[i];
	}
	if (matr != nullptr) {
		delete[]matr;
	}
}
void reader::read_file() {
	fin.open("../input.txt");
	std::getline(fin, s);
	kol_ver = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			kol_ver++;
		}
	}
	matr = new int*[kol_ver];
	for (int i = 0; i < kol_ver; i++) {
		matr[i] = new int[kol_ver];
	}
	for (int i = 0; i < kol_ver; i++) {
		for (int j = 0; j < kol_ver; j++) {
			fin >> matr[i][j];
			if (matr[i][j] > 0) {
				kol_rebr++;
			}
		}
	}
}

int** reader::getMatr() {
	return matr;
}
int reader::getKol_ver() {
	return kol_ver;
}
int reader::getKol_rebr() {
	return kol_rebr;
}
std::string reader::getSt() {
	return s;
}