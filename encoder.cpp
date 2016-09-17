#include "encoder.h"
#include <vector>

Encoder::Encoder(std::set<unsigned int> &pos, std::size_t n_in, std::size_t K): 
	 k(K), n(n_in), N(pow(2, n)), infoPosition(pos.begin(), pos.end())
{
	//info = new unsigned int[k];
	codeword = new int[N];
}


void Encoder::encoder()
{
	for (std::size_t i = 0; i < N; i++)
		codeword[i] = 0;
	for (std::size_t i = 0; i < k; i++) {
		codeword[infoPosition[i]] = info[i];
	}
	realEncoder(0, N, n, N);
}

void Encoder::realEncoder(std::size_t it1, std::size_t it2, std::size_t n, std::size_t N)
{
	if (n == 1)
		codeword[it1] = mod2(codeword[it1], codeword[it1 + 1]);
	else {
		//std::vector<unsigned int> temp(N);
		for (std::size_t i = 0; i < it2-it1; i += 2)
			codeword[it1+i] = mod2(codeword[it1 + i], codeword[it1 + i + 1]);

		reverse_shuffle(it1, it2);
		realEncoder(it1, it1 + N / 2, n - 1, N / 2);
		realEncoder(it1 + N / 2, it2, n - 1, N / 2);


	}
}

void Encoder::reverse_shuffle(std::size_t it1, std::size_t it2)
{
	std::size_t si = it2 - it1;
	if (si == 1)	return;
	int *temp=new int[si];
	for (std::size_t i = 0; i < si / 2; i++) {
		temp[i] = codeword[it1 + 2 * i];
		temp[i + si / 2] = codeword[it1 + 2 * i + 1];
	}
	for (std::size_t i = 0; i < si; i++) {
		codeword[it1 + i] = temp[i];
	}
	delete[] temp;
}
