#include "write.h"
void write::write_ans(ver_sm* ans_ver, std::string* name_ver, int ans, int size) {
	for (int i = 0; i < size; i++) {
		ver1 = ans_ver[i].ver1;
		ver2 = ans_ver[i].ver2;
		std::cout << name_ver[ver1] << ' ' << name_ver[ver2] /*<<' ' << ans_ver[i].ves <<' ' << ver1 << ' ' << ver2*/ << '\n';
	}
	std::cout << ans;
}