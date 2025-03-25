#include "FuncA.h"
#include <cmath>

double FuncA::calculate() {
	double sum = 0.0;
<<<<<<< HEAD
	double x = 0.5;
	for (int n = 0; n < 3; ++n) {
		double numerator = tgamma(2 * n + 1);
		double denominator = pow(4, n) * pow(tgamma(n + 1), 2) * (2 * n + 1);
		sum += (numerator / denominator) * pow(x, 2 * n + 1);
=======
	for (int n = 0; n < N; ++n) {
		double numerator = tgamma(2 * n + 1);
		double denominator = pow(4, n) * pow(tgamma(n + 1), 2) * (2 * n + 1);
		sum += (numerator / denominator) * pow(x, 2* n + 1);
>>>>>>> branchA
	}
	return (M_PI / 2) - sum;
}
