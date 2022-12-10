#include "build.h"
ver_sm* build::build_reb(int kol_reb, int kol_ver, int** matr) {
	vera = new ver_sm[kol_reb];
	p = 0;
	for (int i = 0; i < kol_ver; i++) {
		for (int j = 0; j < kol_ver; j++) {
			if (matr[i][j] > 0) {
				vera[p].ver1 = i;
				vera[p].ver2 = j;
				vera[p].ves = matr[i][j];
				p++;
			}
		}
	}
	/*for (int i = 0; i < kol_reb; i++) {
		std::cout << vera[i].ver1 << ' ' << vera[i].ver2 << ' ' << vera[i].ves << '\n';
	}*/
	return vera;
}
std::string* build::build_ver(std::string s, int kol_ver) {
	p = 0;
	bl_ver = "";
	ver = new std::string[kol_ver];
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			ver[p] = bl_ver;
			bl_ver = "";
			p++;
		}
		else {
			bl_ver += s[i];
		}
	}
	ver[p] = bl_ver;
	/*for (int i = 0; i < kol_ver; i++) {
		std::cout << ver[i] << ' ';
	}*/
	return ver;
}