#include "readF.h"

//void readF()
void readF(const std::string &&file)
{
	double *ptr = &phi_inv_in_out[0][0];
	std::ifstream fin(file);
	while (!fin.eof()) {
		fin >> *ptr;
		ptr++;
	}
	fin.close();	//read the phi function sample file
}