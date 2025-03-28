#include <stdio.h>
#include <iostream>
#include "../FuncA.h"

int main()
{
	FuncA devops;
	double result = devops.calculate(int, double);

	if (std::abs(result) < 1)
	{
		std::cout << "Calculated succesfully";
	} else {
		std::cout << "Calculations failed";
	}
	return 0;
}
