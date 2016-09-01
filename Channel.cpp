#include "Channel.h"

void Channel::add_gauss()
{
	
	std::random_device rd;
	std::mt19937 mt_gen(rd());
	std::normal_distribution<double> norm_dist(0, sigma);

	for (std::size_t i = 0; i < length; i++)				//add the white gaussian noise
		output[i] = input[i] + norm_dist(mt_gen);

}