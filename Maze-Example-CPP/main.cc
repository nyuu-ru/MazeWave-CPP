/*
 * main.cc
 *
 *  Created on: 11 нояб. 2021 г.
 *      Author: unyuu
 */

#include <iostream>
#include <string>
#include <vector>

const std::string map[10] {
	"##########",
	"#        #",
	"### ### ##",
	"#    #   #",
	"## # ## ##",
	"#  #  # ##",
	"# ###    #",
	"# # # ## #",
	"#     #  #",
	"##########",
};
const unsigned
		MAP_WIDTH = 10,
		MAP_HEIGHT = 10,
		START_X = 1, // начальная строка
		START_Y = 1, // начальный столбец
		FINISH_X = 8,
		FINISH_Y = 8;
const int
		EMPTY = 0,
		WALL = -1,
		PATH = -2;

void print_map(int work_map[MAP_HEIGHT][MAP_WIDTH])
{
	for (unsigned row = 0; row < MAP_HEIGHT; ++row) {
		for (unsigned col = 0; col < MAP_WIDTH; ++col) {
			int cell = work_map[row][col];
			if (cell == WALL) {
				std::cout << "\u2588\u2588"; // ██
			} else
			if (cell == PATH) {
				std::cout << "\u2591\u2591"; // ░░
			} else {
				std::cout << "  ";
			}
		}
		std::cout << std::endl;
	}
}

void cook_map(int work_map[MAP_HEIGHT][MAP_WIDTH])
{
	for (unsigned row = 0; row < MAP_HEIGHT; ++row)
		for (unsigned col = 0; col < MAP_WIDTH; ++col) {
			if (map[row][col] == '#')
				work_map[row][col] = WALL;
			else
				work_map[row][col] = EMPTY;
		}
}

int main()
{
	int work_map[MAP_HEIGHT][MAP_WIDTH] {}; // [строка][столбец]

	cook_map(work_map);
//	print_map(work_map);

	int iter = 1;
	work_map[START_X][START_Y] = iter;
	bool found;
	do {
		found = false;
		for (unsigned row = 1; row < MAP_HEIGHT-1; ++row)
			for (unsigned col = 1; col < MAP_WIDTH-1; ++col) {
				if (work_map[row][col] == iter) {
					found = true;
					if (work_map[row][col+1] == 0)
						work_map[row][col+1] = iter + 1;
					if (work_map[row][col-1] == 0)
						work_map[row][col-1] = iter + 1;
					if (work_map[row+1][col] == 0)
						work_map[row+1][col] = iter + 1;
					if (work_map[row-1][col] == 0)
						work_map[row-1][col] = iter + 1;
				}
			}
		if (work_map[FINISH_X][FINISH_Y] != EMPTY)
			break;
		++iter;
	} while (found);

	if (not found) {
		print_map(work_map);
		std::cout << "Нет пути!" << std::endl;
		return 0;
	}

	int x = FINISH_X, y = FINISH_Y;

	/*		work_map[x][y] - текущая клетка.
	 * 		iter = ... - сохраняем значение в переменную iter
	 * 		(iter = work_map[x][y]) - значение из текущей клетки
	 *
	 * while ((iter = work_map[x][y]) != 1) -
	 * 			Пока значение в текущей клетке не равно 1
	 *
	 */

	while ((iter = work_map[x][y]) != 1) {
		work_map[x][y] = PATH;
		if (work_map[x][y-1] == iter-1) --y;
		else if (work_map[x][y+1] == iter-1) ++y;
		else if (work_map[x-1][y] == iter-1) --x;
		else if (work_map[x+1][y] == iter-1) ++x;
		else {
			std::cerr << "Случилось страшное!" << std::endl;
			return 1;
		}
	}
	work_map[x][y] = PATH;
	print_map(work_map);

	return 0;
}


