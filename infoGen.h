#ifndef INFO_GEN_H
#define INFO_GEN_H
//the generator of the information bits
#include <random>
#include <vector>

class infoGen {
public:
	infoGen(int len) :infoLength(len) { info = new int[infoLength]; }
	void gen();
	~infoGen() { delete[] info; }
public:
	std::size_t infoLength;
	int *info;
	
};

#endif
