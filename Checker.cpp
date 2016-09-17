#include "Checker.h"

void Checker::check()
{
	frame_error = 0;
	FER = 0.0;
	if (!isRight())	frame_error++;
}

bool Checker::isRight()
{
	for (std::size_t i = 0; i < K; i++) {
		if (info[i] != u_hat[i])
			return false;
	}
	return true;
}

void Checker::CalculateFER()
{
	FER = (double)frame_error / (double)FRAMES;
}

void Checker::Out()
{
	std::cout << std::endl;
	std::cout << FER << std::endl;
}