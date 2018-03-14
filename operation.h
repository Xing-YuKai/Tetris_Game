#pragma once
#include "block.h"
#include <vector>
#include <utility>
#include <stdlib.h>
#include <algorithm>
#include <iostream>

class operation
{
public:
	void generate_random();
	void change_block_pos(vector<pair<int, int>> &block_pos, vector<vector<char>> &map, int shift_a, int shift_b);
	void display_on_map(vector<vector<char>> &map, vector<pair<int, int>> block_pos);
	void push_to_map(vector<vector<char>> &map, vector<pair<int, int>> &block_pos);
	void call_rotate();
	bool attach_left_right(vector<pair<int, int>> block_pos);
	bool attach_bottom(vector<pair<int, int>> block_pos, vector<vector<char>> map);
	void elimination(vector<vector<char>> &map);
private:
	block obj;
	int random;
};

