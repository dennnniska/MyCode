#include "draw.h"


void draw::draw_choice(int pos){
	system("CLS");
	std::cout << "��� ������" << std::endl;
	std::cout << "�������";
	if (pos == 0) {
		std::cout << "<--";
	}
	std::cout << std::endl;
	std::cout << "������-������";
	if (pos == 1) {
		std::cout << "<--";
	}
	std::cout << std::endl;
	std::cout << "�����";
	if (pos == 2) {
		std::cout << "<--";
	}
	std::cout << std::endl;

}

void draw::draw_usual_tree(int pos) {
	system("CLS");
	std::cout << "��� ��������" << std::endl;
	std::cout << "DFS-start";
	if (pos == 0) {
		std::cout << "<--";
	}
	std::cout << std::endl;
	std::cout << "DFS-average";
	if (pos == 1) {
		std::cout << "<--";
	}
	std::cout << std::endl;
	std::cout << "DFS-end";
	if (pos == 2) {
		std::cout << "<--";
	}
	std::cout << std::endl;
	std::cout << "�����";
	if (pos == 3) {
		std::cout << "<--";
	}
	std::cout << std::endl;
}

void draw::draw_BR(int pos) {
	system("CLS");
	std::cout << "��� ��������" << std::endl;
	std::cout << "DFS-start";
	if (pos == 0) {
		std::cout << "<--";
	}
	std::cout << std::endl;
	std::cout << "DFS-average";
	if (pos == 1) {
		std::cout << "<--";
	}
	std::cout << std::endl;
	std::cout << "DFS-end";
	if (pos == 2) {
		std::cout << "<--";
	}
	std::cout << std::endl;
	std::cout << "BFS";
	if (pos == 3) {
		std::cout << "<--";
	}
	std::cout << std::endl;
	std::cout << "�������� �������";
	if (pos == 4) {
		std::cout << "<--";
	}
	std::cout << std::endl;
	std::cout << "������� �������";
	if (pos == 5) {
		std::cout << "<--";
	}
	std::cout << std::endl;
	std::cout << "����� �������";
	if (pos == 6) {
		std::cout << "<--";
	}
	std::cout << std::endl;
	std::cout << "�����";
	if (pos == 7) {
		std::cout << "<--";
	}
	std::cout << std::endl;
}