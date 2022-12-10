#include "start.h"
void start::begin() {
	read.read_file();
	kol_reb = read.getKol_rebr();
	kol_ver = read.getKol_ver();
	s = read.getSt();
	matr = read.getMatr();
	//comp = compBFS.BFS_cp(matr, kol_ver);
	ver = bl.build_ver(s, kol_ver);
	vera = bl.build_reb(kol_reb, kol_ver, matr);
	sort_.sortMR(vera, kol_reb);
	tree.biuld_OST(vera, kol_ver, kol_reb);
	ans = tree.get_ans();
	ans_ver = tree.get_ans_ver();
	size = tree.get_size();
	_write.write_ans(ans_ver, ver, ans, size);
}

start::~start() {
	if (vera != nullptr) {
		delete[]vera;
	}
	if (ver != nullptr) {
		delete[] ver;
	}
	if (ans_ver != nullptr) {
		delete[] ans_ver;
	}
}