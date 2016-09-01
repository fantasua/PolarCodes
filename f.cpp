#include "f.h"

int compare(const void * kp, const void * vp)
{
	//key is the item I want to search
	double key = *(const double*)kp;
	const double *vec = (const double*)vp;

	//////////////////////////////////////////////////
	//	vec[-1]            vec[0]               vec[1] 
	//     |                |                       |
	//              |                     |
	//  (vec[-1]+vec[0])/2.0        (vec[0]+vec[1])/2.0
	//////////////////////////////////////////////////
	if (key > (vec[0] + vec[1]) / 2.0)
		return 1;
	else if (key < (vec[-1] + vec[0]) / 2.0)
		return -1;
	else
		return 0;
}

double Phi(double x)
{
	//assert x>0
	assert(x >= 0);

	if (x <= 10) {
		return exp(ALFA*pow(x, GAMA) + BETA);
	}
	else if (x>10) {
		return sqrt(PI / x)*exp(-x / 4)*(1 + 1 / (14 * x) - 3 / (2 * x));
	}
}

double Phi_inv(double y, double* phi_inv_in, double *phi_inv_out, int PHI_SAMPLE_LENGTH, int PHI_SAMPLE_RANGE)
{
	assert(y >= 0);

	double * pItem;
	int index;
	pItem = (double*)bsearch(&y, phi_inv_in, PHI_SAMPLE_LENGTH, sizeof(double), compare);
	index = pItem - phi_inv_in;
	return  (pItem != NULL) ? (phi_inv_out[index]) : PHI_SAMPLE_RANGE;
}

double f(double x)
{
	return Phi_inv(1 - pow((1 - Phi(x)), 2), phi_inv_in_out[0], phi_inv_in_out[1], 1000000, phi_inv_in_out[1][0]);
}
