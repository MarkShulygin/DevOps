#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cmath>
#include "../FuncA.h"

int main() {
    FuncA func;
    const int count = 27000000;

    std::vector<double> values(count);

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < count; i++) {
        values[i] = func.calculate();
    }


    std::sort(values.begin(), values.end());

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    double seconds = elapsed.count();
    std::cout << "Execution time: " << seconds << " seconds\n";

    if (seconds >= 5.0 && seconds <= 20.0) {
        std::cout << " Test passed: time in [5-20] sec\n";
        return 0;
    } else {
        std::cout << " Test failed: time out of range\n";
        return 1;
    }
}
