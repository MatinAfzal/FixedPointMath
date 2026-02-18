// Solution.cpp main() - Test Function For fpm.hpp

#include <iostream>
#include "fpm.hpp"

#define COUTX(X) std::cout << X << std::endl
#define COUTE(X, Y)  std::cout << double(X) << " | Offset = " << std::abs(double(X)-Y) << std::endl

// int8_t bits is -128...127 & overflow is possible.
// using unsigned instead.
using fixed8_8 = fixed<uint8_t, uint16_t, 4>; // Possible Overflow!
using fixed16_16 = fixed<int16_t, int32_t, 8>;
using fixed32_32 = fixed<int32_t, int64_t, 16>;

int main()
{
	double dA = 10.5;
	double dB = 4.75;
	fixed16_16 a(dA);
	fixed16_16 b(dB);

	fixed16_16 c, d, e, f;
	c = a + b;
	d = a - b;
	e = a * b;
	f = a / b;

	std::cout << "A = " << double(a) << std::endl;
	std::cout << "B = " << double(b) << std::endl;

	std::cout << "A + B = ";
	c == double(a + b) && c == dA + dB ? COUTX(c) : COUTE(c, dA + dB);

	std::cout << "A - B = ";
	d == double(a - b) && d == dA - dB ? COUTX(d) : COUTE(d, dA - dB);

	std::cout << "A * B = ";
	e == double(a * b) && e == dA * dB ? COUTX(e) : COUTE(e, dA * dB);

	std::cout << "A / B = ";
	f == double(a / b) && f == dA / dB ? COUTX(f) : COUTE(f, dA / dB);

	std::cin.get();
	return EXIT_SUCCESS;
}
