#include <iostream>
#include <chrono>
#include <cstdlib>
#include <thread>
#include <csignal>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<int> aValues;
    std::mt19937 mtre(123); 
    std::uniform_int_distribution<int> distr(0, 2000000);

    for (int i = 0; i < 2000000; i++) {
        aValues.push_back(distr(mtre));
    }

    for (int i = 0; i < 500; i++) {
        std::sort(aValues.begin(), aValues.end());
        std::reverse(aValues.begin(), aValues.end());
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    int iMS = elapsed.count();

    std::cout << "⏱ Execution time: " << iMS << " ms\n";

    if (iMS < 5000) {
        std::cout << "Too fast! (< 5 sec)\n";
        return 1;
    } else if (iMS > 20000) {
        std::cout << "Too slow! (> 20 sec)\n";
        return 1;
    } else {
        std::cout << "Perfect execution time!\n";
	return 0;
    }

    FuncA func;
    double result = func.calculate();

    return 0;
}
