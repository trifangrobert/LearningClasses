#pragma once
#include <ostream>

namespace MathLib
{
	class IntegerNumber
	{
	public:
		IntegerNumber();
		IntegerNumber(char s[]);

		void Print(std::ostream& out);

		bool operator<(const IntegerNumber& other)const;
		IntegerNumber operator+(const IntegerNumber & other)const;
		IntegerNumber operator-(const IntegerNumber &other)const;
		IntegerNumber operator*(const IntegerNumber & other)const;
		IntegerNumber operator/(const IntegerNumber & other)const;
		IntegerNumber operator%(const IntegerNumber & other)const;

		static const int GetMaxDim();

	private:
		IntegerNumber MakeSum(IntegerNumber other)const;
		IntegerNumber MakeDifference(IntegerNumber other)const;
		IntegerNumber MakeProduct(IntegerNumber other)const;
		IntegerNumber MakeDivision(IntegerNumber other)const;
		IntegerNumber MakeModulo(IntegerNumber other)const;
		static bool LessThanHelper(IntegerNumber x, IntegerNumber y);
		static IntegerNumber MakeSum(IntegerNumber a, IntegerNumber b);
		static IntegerNumber MakeDifference(IntegerNumber a, IntegerNumber b);
		static IntegerNumber MakeProduct(IntegerNumber a, IntegerNumber b);
		static IntegerNumber MakeDivision(IntegerNumber a, IntegerNumber b);
		static IntegerNumber MakeModulo(IntegerNumber a, IntegerNumber b);
		static const int MAXDIM = 100;
		int m_v[MAXDIM];
		int m_dim;
		bool m_isNegative;
		bool m_isValid = true;
	};
}