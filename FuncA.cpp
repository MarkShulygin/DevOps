#include "FuncA.h"

double FuncA::calculate() {
	double sum = 0.0;
	for (int n = 0; n < N; ++n) {
		double numerator = tgamma(2 * n + 1);
		double denominator = pow(4, n) * pow(tgamma(n + 1), 2) * (2 * n + 1);
		sum += (numerator / denominator) * pow(x, 2* n + 1);
	}
	return (M_PI / 2) - sum;
}
