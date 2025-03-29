#include <stdio.h>
#include <iostream>
#include "../FuncA.h"
#include "../FuncA.cpp"

int main()
{
	FuncA devops;
	double result = devops.calculate();

	if (std::abs(result) < 2)
	{
		std::cout << "Calculated succesfully";
	} else {
		std::cout << "Calculations failed";
	}
	return 0;
}
