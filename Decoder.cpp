#include "Decoder.h"

void Decoder::decoder()
{
	for (int i = 0; i < N; i++) {
		output[i] = 0;
	}
	for (int i = 0; i < K; i++) {
		u_hat[i] = 0;
	}
	int counter = 0;
	for (int pos = 0; pos < N; pos++) {
		if (infoPos[counter] != pos)
			continue;
		double h0 = logAPP(input, output, 0, N, pos+1, var);
		double h1 = logAPP(input, output, 1, N, pos+1, var);
		output[pos] = (h0 > h1) ? 0 : 1;
		u_hat[counter] = output[pos];
		counter++;
	}
}

void Decoder::realdecoder()
{

}

