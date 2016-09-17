#ifndef ENCODER_H
#define ENCODER_H
//the encoder of the polar code
#include <vector>
#include <set>
class Encoder {
public:
	Encoder(std::set<unsigned int>& pos, std::size_t n_in, std::size_t K);
	~Encoder()
	{
		//delete[] info;
		delete[] codeword;
	}
	unsigned int mod2(unsigned int a, unsigned int b) { return (a + b) % 2; }	//mod2 adder
	void encoder();
	void realEncoder(std::size_t it1, std::size_t it2, std::size_t n, std::size_t N);
	void reverse_shuffle(std::size_t it1, std::size_t it2);	//reverse shuffle operation

public:
	std::size_t k;	//length of the information
	std::size_t n;	//n=log2(N)
	std::size_t N;	//length of the codeword
	std::vector<unsigned int> infoPosition;	//the position of the info bits
	int *info;	//the input of the ecnoder, only the info sequence
	int *codeword;	//the coded bit sequence

};



#endif