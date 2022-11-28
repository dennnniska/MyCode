#include "move.h"
int move::move_pos(int& pos, int N) {
	key = _getche(); // entr = 13 up = 224 72 down = 224 80
	if (key == 224) {
		key = _getche();
		if (key == 72) {
			pos--;
			if (pos == -1) {
				pos = N-1;
			}
		}
		if (key == 80) {
			pos++;
			if (pos == N) {
				pos = 0;
			}
		}
	}
	if (key == 13) {
		return pos;
	}
	return N;
}
