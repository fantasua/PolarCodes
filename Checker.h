//Checker
//store the BER and/or FER
#include <cstddef>
#include <iostream>
class Checker
{
public:
	int *info;			//the original infomation bit sequence
	int *u_hat;			//the decoded infomation bit sequence
	std::size_t K;
	std::size_t frame_error;	//the frame error number
	std::size_t FRAMES;
	double FER;	//the FER


public:
	Checker(std::size_t K_in, std::size_t FRA) :K(K_in), FRAMES(FRA) {}
	void check();
	bool isRight();
	void CalculateFER();
	void Out();
};