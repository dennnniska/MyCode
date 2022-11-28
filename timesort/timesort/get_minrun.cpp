#include "get_minrun.h"
int get_minrun::minrun(int size) {
	int r = 0;
	while (size >= 64) {
		r |= size & 1;
		size >>= 1;
	}
	return size + r;
}