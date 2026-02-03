// Floating point calculations without FPU.
#include <iostream>

typedef long Fixed32; // 16.16 Fixed Point 
Fixed32 FixedMul(Fixed32 x, Fixed32 y);
Fixed32 FixedDiv(Fixed32 x, Fixed32 divisor);

#pragma aux FixedMul =          \
    "imul edx"                  \
    "add eax, 8000h"            \
    "adc edx, 0"                \
    "shrd eax, edx, 16"         \
    parm caller [eax] [edx      \
    value [eax]                 \
    modify [eax edx];

#pragma aux FixedDiv =          \
    "xor eax, eax"              \
    "shrd eax, edx, 16"         \
    "sar edx, 16"               \
    "idiv ebx"                  \
    parm caller [edx] [ebx]     \
    value [eax]                 \
    modify [eax ebx edx];

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
#define PRINT_INFO(info)    std::cout<<"\n"<<info<<std::endl;
//*********************************************************
#define ONE INT_TO_FIXED(1);
#define FIXED_PI        205887L
#define FIXED_2PI       411775L
#define FIXED_E         178144L
#define FIXED_ROOT2      74804L
#define FIXED_ROOT3     113512L
#define FIXED_GOLDEN    106039L
//*********************************************************

void testAdd();

int main()
{
    std::cout << "Fixed32 (long) is " << sizeof(Fixed32) << " bytes." << std::endl;
    testAdd();

    PRINT_INFO("Enter any keys to exit.");
    std::cin.get();
    return EXIT_SUCCESS;
}
//---------------------------------------------------------
void testAdd()
{
    PRINT_INFO("*********Starting testAdd!*********");
    Fixed32 x = 8000.8045;
    Fixed32 y = 0999.0954;
    Fixed32 res = FixedAdd(x, y);
    std::cout << "Fixed32 x + y = " << res << " eq=al to double " << FIXED_TO_DOUBLE(res) << std::endl;
}
