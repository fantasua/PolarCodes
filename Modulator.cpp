#include "Modulator.h"

void Modulator::BPSK(int *input)
{
	for (int i = 0; i < N; i++)
		output[i] = 2 * input[i] - 1;
}
