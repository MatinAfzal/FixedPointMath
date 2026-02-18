#pragma once

template<typename size, typename dsize, size_t pb>
class fixed 
{
public:
	size fixedNum = size(0);
	constexpr fixed() = default;
	constexpr fixed(const double num) 
	{
		fixed::fixedNum = size(num * double(1 << pb) + (num >= 0 ? 0.5 : -0.5));
	}
	static constexpr fixed newInstance(const size fixedNum)
	{
		fixed instance;
		instance.fixedNum = fixedNum;
		return instance;
	}
	
	// Fixed To Double
	constexpr operator double()
	{
		return double(fixedNum) / double(1 << pb);
	}
	
	// Assign
	constexpr fixed& operator = (const fixed& fixed) = default;

	// Addition
	constexpr fixed operator + (const fixed& fixed) 
	{ 
		return newInstance(this->fixedNum + fixed.fixedNum);
	}
	constexpr fixed& operator += (const fixed& fixed)
	{
		this->fixedNum += fixed.fixedNum;
		return *this;
	}

	// Subtraction
	constexpr fixed operator - (const fixed& fixed)
	{
		return newInstance(this->fixedNum - fixed.fixedNum);
	}
	constexpr fixed& operator -= (const fixed& fixed)
	{
		this->fixedNum -= fixed.fixedNum;
		return *this;
	}

	// Multiplication
	constexpr fixed operator * (const fixed& fixed)
	{
		return newInstance(
			(dsize(this->fixedNum) * dsize(fixed.fixedNum)) >> pb
		);
	}
	constexpr fixed& operator *= (const fixed& fixed)
	{
		dsize(this->fixedNum) *= dsize(fixed.fixedNum) >> pb;
		return *this->fixedNum;
	}

	// Division
	constexpr fixed operator / (const fixed& fixed)
	{
		return newInstance(
			(dsize(this->fixedNum) << pb) / dsize(fixed.fixedNum)
		);
	}
	constexpr fixed& operator /= (const fixed& fixed)
	{
		(dsize(this->fixedNum) << pb) /= dsize(fixed.fixedNum);
		return *this->fixedNum;
	}
};