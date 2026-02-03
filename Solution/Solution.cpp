// Floating point calculations without FPU.
#include <iostream>

typedef long Fixed32; // 16.16 Fixed Point 

//*********************************************************
#define INT_TO_FIXED(x)     ((x) << 16)
#define FIXED_TO_INT(x)     ((x) >> 16)
#define DOUBLE_TO_FIXED(x)  ((Fixed32)(x * 65536.0 + 0.5))
#define FIXED_TO_DOUBLE(x)  (((double)x) / 65536.0)
#define ROUND_FIXED_TO_INT(x) (((x) + 0x8000) >> 16)
//*********************************************************
#define FixedAdd(x, y)  (x + y)
#define FixedSub(x, y)  (x - y)
//*********************************************************
#define ONE INT_TO_FIXED(1);
#define FIXED_PI        205887L
#define FIXED_2PI       411775L
#define FIXED_E         178144L
#define FIXED_ROOT2      74804L
#define FIXED_ROOT3     113512L
#define FIXED_GOLDEN    106039L
//*********************************************************

int main()
{
    std::cout << "Fixed32 (long) is " << sizeof(Fixed32) << " bytes." << std::endl;
    std::cin.get();
    return EXIT_SUCCESS;
}