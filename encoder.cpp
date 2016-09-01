#include "encoder.h"
#include <vector>

Encoder::Encoder(std::set<unsigned int> &pos, std::size_t n_in, std::size_t K): 
	 k(K), n(n_in), N(pow(2, n)), infoPosition(pos.begin(), pos.end()), info(k), codeword(N)
{}

Encoder::~Encoder() {}

void Encoder::encoder()
{
	for (int i = 0; i < info.size(); i++) {
		codeword[infoPosition[i]] = info[i];
	}
	realEncoder(codeword.begin(), codeword.end(), n, N);
}

void Encoder::realEncoder(std::vector<unsigned int>::iterator it1, std::vector<unsigned int>::iterator it2, std::size_t n, std::size_t N)
{
	if (n == 1)
		*(it1) = mod2(*it1, *(it1 + 1));
	else {
		//std::vector<unsigned int> temp(N);
		for (int i = 0; i < N; i += 2)
			*(it1+i) = mod2(*(it1 + i), *(it1 + i + 1));

		reverse_shuffle(it1, it2);
		realEncoder(it1, it1 + N / 2, n - 1, N / 2);
		realEncoder(it1 + N / 2, it2, n - 1, N / 2);


	}
}

void Encoder::reverse_shuffle(std::vector<unsigned int>::iterator it1, std::vector<unsigned int>::iterator it2)
{
	std::size_t si = it2 - it1;
	std::vector<unsigned int> temp(si);
	for (int i = 0; i < si / 2; i++) {
		temp[i] = *(it1 + 2 * i);
		temp[i + si / 2] = *(it1 + 2 * i + 1);
	}
	for (int i = 0; i < si; i++) {
		*(it1 + i) = temp[i];
	}
}
