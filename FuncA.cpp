#include "FuncA.h"
#include <cmath>

double FuncA::compute(double x) {
	double result = 0;
	for (int n = 0; n < 3; ++n) {
		result += pow(-1,n) * pow(x,2 * n + 1) / (2 * n + 1);
	}
	return M_PI / 2 - result;
};
