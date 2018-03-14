#include "stdafx.h"
#include "block.h"


block::block()
{
	block_map.resize(4);
}

block::~block()
{
	block_map.~vector();
}

void block::block_generate(int types)
{
	switch (types)
	{
	case 0:
		block_map[0].first = 0;
		block_map[0].second = 0;
		block_map[1].first = 0;
		block_map[1].second = 1;
		block_map[2].first = 0;
		block_map[2].second = 2;
		block_map[3].first = 0;
		block_map[3].second = 3;
		break;
	case 1:
		block_map[0].first = 0;
		block_map[0].second = 0;
		block_map[1].first = 0;
		block_map[1].second = 1;
		block_map[2].first = 0;
		block_map[2].second = 2;
		block_map[3].first = 1;
		block_map[3].second = 1;
		break;
	case 2:
		block_map[0].first = 0;
		block_map[0].second = 0;
		block_map[1].first = 1;
		block_map[1].second = 0;
		block_map[2].first = 1;
		block_map[2].second = 1;
		block_map[3].first = 1;
		block_map[3].second = 2;
		break;
	case 3:
		block_map[0].first = 0;
		block_map[0].second = 2;
		block_map[1].first = 1;
		block_map[1].second = 0;
		block_map[2].first = 1;
		block_map[2].second = 1;
		block_map[3].first = 1;
		block_map[3].second = 2;
		break;
	case 4:
		block_map[0].first = 0;
		block_map[0].second = 1;
		block_map[1].first = 0;
		block_map[1].second = 2;
		block_map[2].first = 1;
		block_map[2].second = 1;
		block_map[3].first = 1;
		block_map[3].second = 2;
		break;
	case 5:
		block_map[0].first = 0;
		block_map[0].second = 1;
		block_map[1].first = 1;
		block_map[1].second = 1;
		block_map[2].first = 1;
		block_map[2].second = 2;
		block_map[3].first = 2;
		block_map[3].second = 2;
		break;
	case 6:
		block_map[0].first = 0;
		block_map[0].second = 2;
		block_map[1].first = 1;
		block_map[1].second = 1;
		block_map[2].first = 1;
		block_map[2].second = 2;
		block_map[3].first = 2;
		block_map[3].second = 1;
		break;
	default:
		break;
	}
}

void block::block_rotate()
{
	for (int i = 0; i < block_map.size(); i++)
	{
		auto tmp = block_map[i];
		block_map[i].first = tmp.second;
		block_map[i].second = 3 - tmp.first;
	}
}

vector<pair<int, int>> block::get_block()
{
	auto tmp = block_map;
	for (int i = 0; i < tmp.size(); i++)
	{
		tmp[i].second += 4;
		tmp[i].first += 1;
	}
	return tmp;
}