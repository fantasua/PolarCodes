#ifndef INFO_GEN_H
#define INFO_GEN_H
//the generator of the information bits
#include <random>
#include <vector>

class infoGen {
public:
	infoGen(unsigned int len):infoLength(len), info(len) {}
	void gen();

public:
	std::size_t infoLength;
	std::vector<unsigned int> info;
	
};

#endif
