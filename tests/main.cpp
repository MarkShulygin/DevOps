#include <iostream>
#include <chrono>
#include <cstdlib>
#include <thread>
#include <csignal>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        execl("./HTTP_Server", "HTTP_Server", NULL);
        perror("execl failed");
        return 1;
    }

    std::this_thread::sleep_for(std::chrono::seconds(2));

    auto start = std::chrono::high_resolution_clock::now();

    int result = system("curl -s http://127.0.0.1:8081/compute > output.txt");

    auto end = std::chrono::high_resolution_clock::now();
    double seconds = std::chrono::duration<double>(end - start).count();

    std::cout << "Request + server execution time: " << seconds << " seconds\n";

    kill(pid, SIGTERM);
    waitpid(pid, nullptr, 0);

    if (result == 0 && seconds >= 5.0 && seconds <= 20.0) {
        std::cout << "Server passed time check\n";
        return 0;
    } else {
        std::cout << "Server too slow/fast or curl failed\n";
        return 1;
    }
}
