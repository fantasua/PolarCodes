#include "Modulator.h"

void Modulator::BPSK(std::vector<unsigned int> &input)
{
	output.resize(input.size());
	for (int i = 0; i < input.size(); i++)
		output[i] = 2 * input[i] - 1;
}
