# fpm.hpp (Simple Fixed Point Math C++ Header Only Library)
Smart Calculation Technique That Saved the Good Old Games Industry (Fixed-Point Math)

**fpm.hpp** is a fixed point math header only library for C++ that you can download from here:  
https://github.com/MatinAfzal/FixedPointMath/blob/main/Solution/fpm.hpp  

Just drag and drop it into your project and include it anywhere, then use it like the test/example below:  
https://github.com/MatinAfzal/FixedPointMath/blob/main/Solution/Solution.cpp  

Tested on C++14 through C++20.

## Example

```cpp
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
```

## Output
```
A = 10.5
B = 4.75
A + B = 15.25
A - B = 5.75
A * B = 49.875
A / B = 2.20703
```
