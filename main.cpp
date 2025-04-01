#include <iostream>
#include <stdio.h>
#include "FuncA.h"

extern int CreateHTTPserver();

int main() {
	FuncA f;
	std::cout << "Result: " << f.calculate() << std::endl;
	return CreateHTTPserver();
};
