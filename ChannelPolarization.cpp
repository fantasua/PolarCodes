#include "ChannelPolarization.h"


ChannelPolarization::ChannelPolarization(std::size_t Ni, std::size_t ni, std::size_t Ki, double r):
	N(Ni), n(ni), K(Ki), infoSet(), R(r)
{
}

void ChannelPolarization::getChannels(double sigma2)
{
	
	std::vector<std::pair<int, double> > channels(N);
	for (int i = 0; i < channels.size(); i++)
		channels[i].first = i;
	std::vector<double> temp(N, 0);
	channels[0].second = 2 / sigma2;

	for (std::size_t cn = 2; cn <= N; cn *= 2) {	//calculate the polarized channels
		for (std::size_t ci = 0; ci < cn / 2; ci++)
			temp[ci] = channels[ci].second;
		for (std::size_t ci = 0; ci < cn / 2; ci++) {
			channels[2 * ci].second = f(temp[ci]);
			channels[2 * ci + 1].second = 2 * temp[ci];
		}
	}
	
	std::sort(channels.begin(), channels.end(), 
		[](std::pair<int, double>&a, std::pair<int, double> &b) { return a.second > b.second; });
	for (int i = 0; i < K; i++)
		infoSet.insert(channels[i].first);
}

