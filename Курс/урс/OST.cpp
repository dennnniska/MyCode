#include "OST.h"
void OST::biuld_OST(ver_sm* vera, int kol_ver, int kol_reb) {
	comp = new int[kol_ver];
	for (int i = 0; i < kol_ver; i++) {
		comp[i] = i;
	}
	ans = 0;
	size_ver = 0;
	size = 3;
	ans_ver = new ver_sm[size];
	for (int i = 0; i < kol_reb; i++) {
		if (size_ver == kol_ver - 1) {
			break;
		}
		if (comp[vera[i].ver1] != comp[vera[i].ver2]) {

			for (int j = 0; j < kol_reb; j++) {
				if (comp[j] == comp[vera[i].ver2]) {
					comp[j] = comp[vera[i].ver1];
				}
			}

			ans += vera[i].ves;

			if (size == size_ver + 1) {
				size = size + 10;
				bl_ver = new ver_sm[size];
				for (int j = 0; j < size_ver; j++) {
					bl_ver[j] = ans_ver[j];
				}
				delete[]ans_ver;
				ans_ver = bl_ver;
			}

			ans_ver[size_ver] = vera[i];
			size_ver++;
		}
	}
}
	

OST::~OST() {
	if (comp != nullptr) {
		delete[] comp;
	}
}

int OST::get_ans() {
	return ans;
}
ver_sm* OST::get_ans_ver() {
	return ans_ver;
}

int OST::get_size() {
	return size_ver;
}