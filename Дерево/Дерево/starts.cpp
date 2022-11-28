#include "starts.h"
void starts::main() {
	reader.reads();
	line = reader.get_line();;
	is_ok = checks.all_right(line);
	if (!is_ok) {
		return;
	}
	pos = 0;
	while (true) {
		console.draw_choice(pos);
		option = key.move_pos(pos, 3);
		if (option == 0) {
			tree_us.usual_tree(line);
		}
		if (option == 1) {
			BRtree_.usual_tree(line);
		}
		if (option == 2) {
			break;
		}
	}
}