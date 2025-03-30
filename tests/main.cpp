#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cmath>
#include "../FuncA.h"

int main() {
    FuncA func;
    auto start = std::chrono::high_resolution_clock::now();

    int result = system("curl -s http://localhost:8081/compute");

    auto end = std::chrono::high_resolution_clock::now();
    double seconds = std::chrono::duration<double>(end - start).count();

    std::cout << "Request + server execution time: " << seconds << " seconds\n";

    if (seconds >= 5.0 && seconds <= 20.0) {
        std::cout << "Server passed time check\n";
        return 0;
    } else {
        std::cout << "Server too slow/fast\n";
        return 1;
    }
}

