#include "usual.h"
void usual::usual_tree(std::string line) {
	_tree.build(line);	
	pos = 0;
	while (true) {
		draw_usual.draw_usual_tree(pos);
		if (pos == 0) {
			_tree.DFS_start(_tree.get_head());
		}
		if (pos == 1) {
			_tree.DFS_average(_tree.get_head());
		}
		if (pos == 2) {
			_tree.DFS_end(_tree.get_head());
		}
		if (pos == 3 && option == 3) {
			//_tree.clean(_tree.get_head());
			break;
		}
		option = key.move_pos(pos, 4);
	}
}


