#pragma once
#include <vector>
#include <utility>

using namespace std;

class block
{
public:
	block();
	void block_generate(int types);
	void block_rotate();
	vector<pair<int, int>> get_block();
	~block();
private:
	vector<pair<int, int>> block_map;
};

