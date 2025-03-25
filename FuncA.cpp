#include "FuncA.h"
#include <cmath>

double FuncA::calculate(int N, double x) {
    double sum = 0.0;
    for (int n = 0; n < N; ++n) {
        double num = tgamma(2 * n + 1);
        double denom = pow(4, n) * pow(tgamma(n + 1), 2) * (2 * n + 1);
        sum += (num / denom) * pow(x, 2 * n + 1);
    }
    return M_PI / 2 - sum;
}
