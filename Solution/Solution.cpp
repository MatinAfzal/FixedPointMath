#include <iostream>
#include "fpm.hpp"

using fixed16_16 = fixed<int16_t, int32_t, 16>;

int main() 
{
	fixed16_16 a(4.75);
	fixed16_16 b(10.5);

	fixed16_16 abSum = a + b;
	fixed16_16 abSub = a - b;
	fixed16_16 abMul = a * b;
	fixed16_16 abDiv = a / b;

	//std::cout << "A = " << a << std::end;

	std::cin.get();
	return EXIT_SUCCESS;
}