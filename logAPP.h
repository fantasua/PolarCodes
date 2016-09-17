extern "C"
{
#include <math.h>
#include <stdlib.h>
}

#define PI 3.1415926
#define MAX(a,b) ((a>b)?a:b)
#define ABS(x) (x>=0?x:-x)

double W(double y, int x, double var);
double maxStar(double x, double y);
double logAPPbase(double y, int x, double var);
double logAPP(double y[], int u_hat[], int ui, int N, int i, double var);
