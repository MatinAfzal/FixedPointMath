// Solution.cpp main() - Test Function For fpm.hpp

#include <iostream>
#include "fpm.hpp"

// int8_t bits is -128...127 & overflow is possible.
// using unsigned instead.
using fixed8_8 = fixed<uint8_t, uint16_t, 4>; 
using fixed16_16 = fixed<int16_t, int32_t, 8>;
using fixed32_32 = fixed<int32_t, int64_t, 16>;

int main() 
{
	fixed16_16 a(10.5);
	fixed16_16 b(4.75);

	fixed16_16 c, d, e, f;
	c = a + b; 
	d = a - b; 
	e = a * b;
	f = a / b;

	std::cout << "A = " << double(a) << std::endl;
	std::cout << "B = " << double(b) << std::endl;

	std::cout << "A + B = ";
	c == double(a + b) ? std::cout << c << std::endl : std::cout << "ERROR" << std::endl;

	std::cout << "A - B = ";
	d == double(a - b) ? std::cout << d << std::endl : std::cout << "ERROR" << std::endl;

	std::cout << "A * B = ";
	e == double(a * b) ? std::cout << e << std::endl : std::cout << "ERROR" << std::endl;

	std::cout << "A / B = ";
	f == double(a / b) ? std::cout << f << std::endl : std::cout << "ERROR" << std::endl;

	std::cin.get();
	return EXIT_SUCCESS;
}