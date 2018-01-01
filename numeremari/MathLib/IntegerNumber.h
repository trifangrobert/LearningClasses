#pragma once
#include <ostream>
#include <string>

namespace MathLib
{
	class IntegerNumber
	{
	public:
		IntegerNumber(long long nr = 0LL);
		IntegerNumber(std::string s);
		IntegerNumber(const IntegerNumber &other);
		~IntegerNumber();
		
		void Reserve(int x);
		void Reset();
		void Print(std::ostream& out);
		int GetSize()const;
		int GetCapacity()const;
		int const * GetRawData()const;

		bool operator<(const IntegerNumber& other)const;
		IntegerNumber& operator=(const IntegerNumber & other);
		IntegerNumber operator+(const IntegerNumber & other)const;
		IntegerNumber operator-(const IntegerNumber &other)const;
		IntegerNumber operator*(const IntegerNumber & other)const;
		IntegerNumber operator/(const int & other)const;
		IntegerNumber operator%(const int & other)const;

	private:
		IntegerNumber MakeSum(IntegerNumber other)const;
		IntegerNumber MakeDifference(IntegerNumber other)const;
		IntegerNumber MakeProduct(IntegerNumber other)const;
		IntegerNumber MakeDivision(int other)const;
		IntegerNumber MakeModulo(int other)const;
		static bool LessThanHelper(IntegerNumber x, IntegerNumber y);
		static IntegerNumber MakeSum(IntegerNumber a, IntegerNumber b);
		static IntegerNumber MakeDifference(IntegerNumber a, IntegerNumber b);
		static IntegerNumber MakeProduct(IntegerNumber a, IntegerNumber b);
		static IntegerNumber MakeDivision(IntegerNumber a, int b);
		static IntegerNumber MakeModulo(IntegerNumber a, int b);
		static int NumberOfDigits(long long a);
		int *m_v;
		int m_dim;
		int m_capacity = 0;
		bool m_isNegative;
		bool m_isValid = true;
	};
}