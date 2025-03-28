#include <stdio.h>
#include <iostream>
#include "../FuncA.h"

int main(int argc, char* argv[])
{
	FuncA devops;
	double result = func.calculate();

	if (std::abs(result) < 1)
	{
		std::cout << "Calculated succesfully";
	} else {
		std::cout << "Calculations failed";
	}
	return 0;
}
