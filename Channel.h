#ifndef CHANNEL_H
#define CHANNEL_H
//the awgn channel
#include <random>
//#include <vector>
class Channel {
public:
	Channel() = default;
	/*
	Channel(double snr, std::vector<unsigned int>& in, double r) :
		SNR_dB(snr), input(in), R(r) {
		length = input.size();
		double SNR_not_dB = pow(10,0.1*SNR_dB);
		sigma2 = 1 / (2 * R*SNR_not_dB);
		sigma = sqrt(sigma2);
		output.resize(length);
	}
	*/
	Channel(double snr, unsigned int len, double r) :SNR_dB(snr), length(len), R(r)
	{
		//input = new int[length];
		double SNR_not_dB = pow(10, 0.1*SNR_dB);
		sigma2 = 1 / (2 * R*SNR_not_dB);
		sigma = sqrt(sigma2);
		output = new double[length];
	}
	~Channel()
	{ 
		//delete[] input; 
		delete[] output;
	}
	void add_gauss();			//gaussian white noise

public:
	double R;
	double SNR_dB;
	double sigma2;
	double sigma;
	std::size_t length;

	int *input;	//input sequence
	double *output;	//output sequence

};


#endif