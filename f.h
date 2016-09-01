extern "C"
{
	#include <stdlib.h>
	#include <assert.h>
	#include <string.h>
}
#include <cmath>
#include <fstream>

static const double ALFA = -0.4527;
static const double BETA = 0.0218;
static const double GAMA = 0.86;
static const double PI = 3.1415926535897932384626433832795;
extern double phi_inv_in_out[2][1000000];


int compare(const void * kp, const void * vp);
double Phi(double x);
double Phi_inv(double y, double* phi_inv_in, double *phi_inv_out, int PHI_SAMPLE_LENGTH, int PHI_SAMPLE_RANGE);
double f(double x);