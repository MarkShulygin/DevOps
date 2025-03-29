#include <stdio.h>
#include <iostream>
#include "../FuncA.h"
#include "../FuncA.cpp"

int main()
{
	FuncA func;
	double result = func.calculate();

	if (std::abs(result) < 1)
	{
		std::cout << "Calculated succesfully";
	} else {
		std::cout << "Calculations failed";
	}
	return 0;
}
