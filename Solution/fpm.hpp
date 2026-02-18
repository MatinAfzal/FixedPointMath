#pragma once

template<typename size, typename dsize, size_t pb>
class fixed 
{
public:
	size fixedNum = size(0);
	constexpr fixed() = default;
	constexpr fixed(const double num) 
	{
		fixed::fixedNum = num * (1 << pb) + (num >= 0 ? 0.5 : -0.5);
	}
	constexpr fixed newInstance(size fixedNum)
	{
		fixed instance;
		instance.fixedNum = fixedNum;
		return instance;
	}
	
	// Fixed To Double
	constexpr operator double()
	{
		return double(fixedNum) / (1 << pb);
	}
	
	// Assign
	constexpr fixed& operator = (const fixed& fixed) = default;

	// Addition
	constexpr fixed& operator + (const fixed& fixed) 
	{ 
		return newInstance(this->fixedNum += fixed.fixedNum);
	}
	constexpr fixed& operator += (const fixed& fixed)
	{
		return *(this->fixedNum += fixed.fixedNum);
	}

	// Subtraction
	constexpr fixed& operator - (const fixed& fixed)
	{
		return newInstance(this->fixedNum -= fixed.fixedNum);
	}
	constexpr fixed& operator -= (const fixed& fixed)
	{
		return *(this->fixedNum -= fixed.fixedNum);
	}

	// Division
	constexpr fixed& operator / (const fixed& fixed)
	{
		return newInstance(
			(dsize(this->fixedNum) /= dsize(fixed.fixedNum) << pb)
		);
	}
	constexpr fixed& operator /= (const fixed& fixed)
	{
		*(dsize(this->fixedNum) /= dsize(fixed.fixedNum) << pb);
	}

	// Multiplication
	constexpr fixed& operator * (const fixed& fixed)
	{
		return newInstance(
			(dsize(this->fixedNum) *= dsize(fixed.fixedNum) >> pb)
		);
	}
	constexpr fixed& operator *= (const fixed& fixed)
	{
		*(dsize(this->fixedNum) *= dsize(fixed.fixedNum) >> pb);
	}
};