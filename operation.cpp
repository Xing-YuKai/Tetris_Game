#include "stdafx.h"
#include "operation.h"

void operation::generate_random()
{
	random = rand() % 7;
	obj.block_generate(random);
}

void operation::change_block_pos(vector<pair<int, int>> &block_pos, vector<vector<char>> &map, int shift_a, int shift_b)
{
	for (auto i : block_pos)
	{
		map[i.first][i.second] = ' ';
	}
	block_pos = obj.get_block();
	for (int i = 0; i < block_pos.size(); i++)
	{
		block_pos[i].first += shift_a;
		block_pos[i].second += shift_b;
	}
}

void operation::display_on_map(vector<vector<char>> &map, vector<pair<int, int>> block_pos)
{
	for (auto i : block_pos)
	{
		map[i.first][i.second] = 'o';
	}
}

void operation::push_to_map(vector<vector<char>> &map, vector<pair<int, int>> &block_pos)
{
	for (int i = 0 ; i<block_pos.size();i++)
	{
		map[block_pos[i].first][block_pos[i].second] = 'O';
		block_pos[i].first = 1;
		block_pos[i].second = 1;
	}
}


void operation::call_rotate()
{
	obj.block_rotate();
}

bool operation::attach_left_right(vector<pair<int, int>> block_pos)
{
	int min, max;
	min = std::min({ block_pos[0].second, block_pos[1].second, block_pos[2].second, block_pos[3].second });
	max = std::max({ block_pos[0].second, block_pos[1].second, block_pos[2].second, block_pos[3].second });
	if (max == 11 || min == 0)
		return true;
	else
		return false;
}

bool operation::attach_bottom(vector<pair<int, int>> block_pos, vector<vector<char>> map)
{
	for (auto i : block_pos)
	{
		if (map[i.first + 1][i.second] == 'O' || map[i.first + 1][i.second] == '#')
			return true;
	}
	return false;
}

void operation::elimination(vector<vector<char>> &map)
{
	for (int i = 1; i < 21; i++)
	{
		bool switcher = true;
		for (int j = 1; j < 11; j++)
		{
			if (map[i][j] != 'O')
			{
				switcher = false;
				break;
			}
		}
		if (switcher)
		{
			for (int j = 1; j < 11; j++)
			{
				map[i][j] = ' ';
			}
			for (int a = i - 1; a > 0; a--)
			{
				for (int b = 1; b < 11; b++)
				{
					swap(map[a][b], map[a+1][b]);
				}
			}
		}
	}
}