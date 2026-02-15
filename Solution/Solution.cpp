#include <iostream>

template<typename size, typename dszie, size_t pb> // size, double size, precision bits.
class FixedPoint 
{
public:
	constexpr FixedPoint() = default;
	constexpr FixedPoint(const double num) { fixed = num * (1 << pb) + (num >= 0 ? 0.5 : -0.5); }
	constexpr size getDouble() { return fixed / (1 << pb); }
	constexpr void setFixed(const size num) { fixed = num; }
	constexpr size getFixed() { return this->fixed; }
	constexpr void add(const FixedPoint num) { fixed += num.fixed; }
	constexpr void sub(const FixedPoint num) { fixed -= num.fixed; }
	constexpr void mul(const FixedPoint num) { fixed = dsize(fixed) * dszie(num.fixed) >> pb; }
	constexpr void div(const FixedPoint num) { fixed = dsize(fixed) / dszie(num.fixed) >> pb; }
private:
	size fixed = size(0);
};

int main() 
{
	using FP16_16 = FixedPoint<int32_t, int64_t, 16>;
	double da = 5.5;
	double db = 7.2;

	FP16_16 fa(da);
	FP16_16 fb(db);

	std::cout << "DOUBLE A: " << da << std::endl;
	std::cout << "DOUBLE B: " << db << std::endl;
	std::cout << "FIXED A: " << fa.getFixed() << std::endl;
	std::cout << "FIXED B: " << fb.getFixed() << std::endl;

	fa.add(fb);
	std::cout << "FIXED A + B = " << fa.getFixed() << std::endl;
	std::cout << "DOUBLE A + B = " << fa.getDouble() << std::endl;

	std::cin.get();
	return EXIT_SUCCESS;
}