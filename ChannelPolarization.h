#ifndef CHANNEL_POLARIZATION_H
#define CHANNEL_POLARIZATION_H
//polarize the channels and find the frozen bits and info bits
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
#include "f.h"




class ChannelPolarization {
public:
	ChannelPolarization(std::size_t Ni, std::size_t ni, std::size_t Ki, double r);
	ChannelPolarization(std::size_t ni, std::size_t Ki, double r) :ChannelPolarization(pow(2, ni), ni, Ki, r) {}
	ChannelPolarization() {}
	~ChannelPolarization() {}


	void getChannels(double sigma2);	//calulate the polarized channels and find out the info sets
public:
	double R;	//the code rate
	std::size_t n;
	std::size_t N;	//the code length
	std::size_t K;	//the info length
	

	//std::vector<double> channels;
	std::set<unsigned int> infoSet;


};



#endif 
