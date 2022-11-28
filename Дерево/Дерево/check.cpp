#include "check.h"
bool check::all_right(std::string line) {
	sk = 0;
	for (int i = 0; i < line.size(); i++) {
		if (line[i] == '(') {
			sk++;
		}
		if (line[i] == ')') {
			sk--;
		}
		if (sk < 0) {
			std::cout << "Не правильное раставление скобок" << std::endl;
			return false;
		}
		if (!(line[i] == '(' || line[i] == ')' || (line[i] >= '0' && line[i] <= '9'))) {
			std::cout << "Неправильный симвл" << std::endl;
			return false;
		}
	}
	if (sk != 0) {
		std::cout << "Не правильное раставление скобок" << std::endl;
		return false;
	}
	values = 0;
	for (int i = 0; i < line.size(); i++) {
		if (line[i] == '(') {
			values++;
			if (values > 2) {
				std::cout << "Не двоичное дерево" << std::endl;
				return false;
			}
			if (i > 0) {
				if (!(line[i - 1] >= '0' && line[i - 1] <= '9') && values == 1) {
					std::cout << "Нет значений ребер" << std::endl;
					return false;
				}
			}
			stapls.push(values);
			values = 0;
		}
		if (line[i] == ')') {
			values = stapls.top();
			stapls.pop();
			if (line[i - 1] == '(') {
				return false;
			}
		}
	}
	if (values != 1) {
		std::cout << "Не двоичное дерево" << std::endl;
		return false;
	}
}
