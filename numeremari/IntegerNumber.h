#pragma once
#include <ostream>

namespace MathLib
{
	class IntegerNumber
	{
	public:
		IntegerNumber(int vectorLength = 0);
		IntegerNumber(char s[]);
		IntegerNumber(const IntegerNumber &other);
		//~IntegerNumber();

		void Print(std::ostream& out);

		bool operator<(const IntegerNumber& other)const;
		IntegerNumber& operator=(const IntegerNumber & other);
		IntegerNumber operator+(const IntegerNumber & other)const;
		IntegerNumber operator-(const IntegerNumber &other)const;
		IntegerNumber operator*(const IntegerNumber & other)const;
		IntegerNumber operator/(const IntegerNumber & other)const;
		IntegerNumber operator%(const IntegerNumber & other)const;

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
		int *m_v;
		int m_dim;
		int m_capacity = 0;
		bool m_isNegative;
		bool m_isValid = true;
	};
}