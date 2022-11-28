#include "BR_tree.h"
#include <iostream>
void BR_tree::build(std::string line) {
	if (!tree.emply()) {
		return;
	}
	int values = 0;
	for (int i = 1; i < line.size(); i++) {
		if (line[i] == '(') {
			tree.insert(values);
			values = 0;
			continue;
		}
		if (line[i] == ')') {
			continue;
		}
		values = values * 10 + line[i] - '0';
	}
	tree.insert(values);
}

void BR_tree::usual_tree(std::string line) {
	build(line);
	pos = 0;
	while (true) {
		draw_usual.draw_BR(pos);
		if (pos == 0) {
			tree.preOrder();
		}
		if (pos == 1) {
			tree.inOrder();
		}
		if (pos == 2) {
			tree.postOrder();
		}
		if (pos == 3) {
			tree.BFS();
		}
		if (pos == 4 && option == 4) {
			printf("Введите число:");
			std::cin >> values;
			tree.insert(values);
		}
		if (pos == 5 && option == 5) {
			printf("Введите число:");
			std::cin >> values;
			tree.remove(values);
		}
		if (pos == 6 && option == 6) {
			printf("Введите число:");
			std::cin >> values;
			if (tree.search(values)) {
				printf("\nТакой элемет есть");
			}
			else {
				printf("\nТакого элемента нет");
			}
		}
		if (pos == 7 && option == 7) {
			break;
		}
		option = key.move_pos(pos, 8);
	}

}