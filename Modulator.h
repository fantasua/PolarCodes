#ifndef MODULATOR
#define MODULATOR
//the modulator
#include <vector>

class Modulator {
public://Constructor
	Modulator() = default;
	Modulator(std::size_t n):N(n) { output = new int[n]; }
public:
	void BPSK(int *input);	//BPSK modulation, 0 -> -1, 1 -> 1  
public:
	int *output;			//output of the modulator
	std::size_t N;

	~Modulator() { delete[] output; };
};

#endif