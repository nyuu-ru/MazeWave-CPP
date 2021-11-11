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
		START_X = 1,
		START_Y = 1,
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
	print_map(work_map);





	return 0;
}


