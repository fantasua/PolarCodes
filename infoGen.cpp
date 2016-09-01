#include "infoGen.h"

void infoGen::gen()
{
	std::random_device rd;
	std::mt19937 mt_gen(rd());
	std::uniform_int_distribution<int> uni_int_dist(0, 1);
	for (std::size_t i = 0; i < infoLength; i++)
		info[i] = uni_int_dist(mt_gen);

}
