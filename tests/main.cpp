#include <iostream>
#include <chrono>
#include <cstdlib>
#include <thread>
#include <csignal>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    auto t1 = std::chrono::high_resolution_clock::now();	

	std::vector<int> aValues;
	// Mersenne Twister random engine
	std::mt19937 mtre {123};
	std::uniform_int_distribution<int> distr {0, 2000000};

	for (int i=0; i<2000000; i++) {
		aValues.push_back(distr(mtre));
	}

	for (int i=0; i<500; i++)
	{
		sort(begin(aValues), end(aValues));
		reverse(begin(aValues), end(aValues));
	}
			
	auto t2 = std::chrono::high_resolution_clock::now();
	auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
	int iMS = int_ms.count();

	char strTimeElapsed[100];
	char message[100];

	if (iMS < 5000) {
   		snprintf(message, sizeof(message), "Too fast! (%d ms)", iMS);
	} else if (iMS > 20000) {
    	snprintf(message, sizeof(message), "Too slow! (%d ms)", iMS);
	} else {
    	snprintf(message, sizeof(message), "Perfect execution time: %d ms", iMS);
	}

	sprintf(strResponse, "%sContent-type: text/html\r\nContent-Length: %lu\r\n\r\n", HTTP_200HEADER, strlen(message));

	write(clientSocket, strResponse, strlen(strResponse));
	write(clientSocket, message, strlen(message));

	printf("\nResponse sent: %s\n", message);
}
