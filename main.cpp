#include "readF.h"
#include "Channel.h"
#include "ChannelPolarization.h"
#include "encoder.h"
#include "infoGen.h"
#include "Modulator.h"
#include <cmath>
#include <iostream>
double phi_inv_in_out[2][1000000] = { 0 };



int main()
{
	readF("phi_inv_in_out.txt");
	std::size_t FRAMES(1000);	//the frames of each SNR
	std::size_t MAX_ERROR(100);	//the error number reaches the MAX_ERROR, stop the simulation
	std::size_t errors(0);			//the actual error number of the simulation
	double SNR_dB(0.0);				//the SNR (in dB)

	std::size_t n(4);
	std::size_t N(std::pow(2, n));	//code length
	std::size_t K(8);					//info length
	double codeRate((double)K / (double)N);			//code rate


	Channel cha(SNR_dB, N, codeRate);	//awgn channel
	ChannelPolarization chaPor(N, n, K, codeRate);		//channel polarization process
	infoGen info(K);			//infomation bit sequence generator
	Modulator wave(N);			//Modulator BPSK

	chaPor.getChannels(cha.sigma2);
	Encoder encoder(chaPor.infoSet, n, K);	//the encoder

	for (int frame = 1; frame <= FRAMES; frame++) {
		info.gen();					//generate the information bit sequence
		encoder.info = info.info;	//send the info bit into the encoder
		encoder.encoder();			//encode the info bits and get the codeword
		wave.BPSK(encoder.codeword);//BPSK
	
		cha.input = wave.output;	//awgn
		cha.add_gauss();

		std::cout << frame << std::endl;
	}
	
	
	

	


	return 0;
}