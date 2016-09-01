#ifndef MODULATOR
#define MODULATOR
//the modulator
#include <vector>

class Modulator {
public://Constructor
	Modulator() = default;
	Modulator(std::size_t n) : output(n) {}
public:
	void BPSK(std::vector<unsigned int>& input);	//BPSK modulation, 0 -> -1, 1 -> 1  
public:
	std::vector<int> output;			//output of the modulator


	~Modulator() {};
};

#endif