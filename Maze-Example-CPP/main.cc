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
const int
		MAP_WIDTH = map[0].length(),
		MAP_HEIGHT = sizeof(map),
		START_X = 1,
		START_Y = 1,
		FINISH_X = 8,
		FINISH_Y = 8,
		EMPTY = 0,
		WALL = -1,
		PATH = -2;



int main()
{
	int work_map[MAP_WIDTH][MAP_HEIGHT];

	for (unsigned row = 0; row < MAP_HEIGHT; ++row)
		for (unsigned col = 0; col < MAP_WIDTH; ++col) {

		}



	return 0;
}


