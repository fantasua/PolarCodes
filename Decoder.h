#ifndef DECODER_H
#define DECODER_H
//the decoder
#include <vector>
#include <set>
#include "logAPP.h"
class Decoder
{
public:
	double *input;							//input of the decoder
	int *output;					//output of the decoder, whose length is N, the x_hat
	int *u_hat;					//the estimate of the infomation coded in the codeword
	std::vector<unsigned int> infoPos;			//the info position set
	int N;									//length of the codeword
	int K;									//length of the infomation
	double var;								//the variance of the channel


public:
	Decoder(int N_in, int k_in, std::set<unsigned int> infoSet_in, double var_in) :N(N_in), 
		K(k_in), infoPos(infoSet_in.begin(), infoSet_in.end()), var(var_in)
	{
		output = new int[N];
		u_hat = new int[K];
	}


	void decoder();
	void realdecoder();
	~Decoder()
	{
		delete[] output;
		delete[] u_hat;
	}
	
};

#endif 
