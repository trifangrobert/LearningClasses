#include "IntegerNumber.h"
#include <cstring>
#include <algorithm>

using namespace std;
using namespace MathLib;

IntegerNumber::IntegerNumber(int vectorLength)
{
	if (vectorLength == 0)
	{
		vectorLength = 5;
	}
	m_capacity = vectorLength;
	m_dim = 1;
	m_isNegative = false;
	m_isValid = true;
	m_v = new int[vectorLength];
	for (int i = 0;i < vectorLength;++i)
		m_v[i] = 0;
}

IntegerNumber::IntegerNumber(char s[])
{
	m_dim = 0;
	m_isNegative = false;
	int lgSir = strlen(s);
	int vectorLength = lgSir + 10;
	m_v = new int[vectorLength];
	m_capacity = vectorLength;
	for (int i = 0;i < vectorLength;++i)
		m_v[i] = 0;
	int x = 0, n = lgSir - 1, pos = 0;;
	if (s[0] == '-')
	{
		++x;
		m_isNegative = true;
	}
	else
		m_isNegative = false;
	for (int i = n;i >= 0 + x;--i)
		m_v[++pos] = (int)(s[i] - '0');
	m_dim = pos;
}

MathLib::IntegerNumber::IntegerNumber(const IntegerNumber & other)
{
	this->m_dim = other.m_dim;
	this->m_capacity = other.m_capacity;
	this->m_v = new int[other.m_capacity];
	this->m_isNegative = other.m_isNegative;
	this->m_isValid = other.m_isValid;
	for (int i = 0; i < other.m_capacity; ++i)
	{
		this->m_v[i] = other.m_v[i];
	}
}

IntegerNumber& IntegerNumber::operator=(const IntegerNumber & other)
{
	this->m_dim = other.m_dim;
	this->m_capacity = other.m_capacity;
	this->m_v = new int[other.m_capacity];
	this->m_isNegative = other.m_isNegative;
	this->m_isValid = other.m_isValid;
	for (int i = 0; i < other.m_capacity; ++i)
	{
		this->m_v[i] = other.m_v[i];
	}
	return *this;
}

bool IntegerNumber::operator<(const IntegerNumber& other)const
{
	if (this->m_isNegative && !other.m_isNegative)
		return true;
	if (!this->m_isNegative && other.m_isNegative)
		return false;
	if (this->m_isNegative && other.m_isNegative)
		return LessThanHelper(*this, other);
	return !LessThanHelper(*this, other);
}

IntegerNumber IntegerNumber::operator+(const IntegerNumber & other) const
{
	return this->MakeSum(other);
}

IntegerNumber IntegerNumber::operator-(const IntegerNumber & other) const
{
	return this->MakeDifference(other);
}

IntegerNumber IntegerNumber::operator*(const IntegerNumber & other) const
{
	return this->MakeProduct(other);
}

IntegerNumber IntegerNumber::operator/(const IntegerNumber & other) const
{
	return this->MakeDivision(other);
}

IntegerNumber IntegerNumber::operator%(const IntegerNumber & other) const
{
	return this->MakeModulo(other);
}

IntegerNumber IntegerNumber::MakeSum(IntegerNumber other)const
{
	if (!this->m_isNegative && !other.m_isNegative)
		return MakeSum(*this, other);
	else if (this->m_isNegative && other.m_isNegative)
	{
		IntegerNumber aux = MakeSum(*this, other);
		aux.m_isNegative = true;
		return aux;
	}
	else if (!this->m_isNegative && other.m_isNegative)
	{
		if (LessThanHelper(*this, other))
		{
			IntegerNumber aux = MakeDifference(other, *this);
			if (aux.m_dim == 1 && aux.m_v[1] == 0)
				aux.m_isNegative = false;
			else
				aux.m_isNegative = true;
			return aux;
		}
		else
		{
			return MakeDifference(*this, other);
		}
	}
	else
	{
		if (LessThanHelper(*this, other))
		{
			return MakeDifference(other, *this);
		}
		else
		{
			IntegerNumber aux = MakeDifference(*this, other);
			if (aux.m_dim == 1 && aux.m_v[1] == 0)
				aux.m_isNegative = false;
			else
				aux.m_isNegative = true;
			return aux;
		}
	}
}
IntegerNumber IntegerNumber::MakeDifference(IntegerNumber other)const
{
	if (!this->m_isNegative && !other.m_isNegative)
	{
		if (LessThanHelper(*this, other))
		{
			IntegerNumber aux = MakeDifference(other, *this);
			aux.m_isNegative = true;
			return aux;
		}
		else
		{
			if (!LessThanHelper(*this, other))
			{
				return MakeDifference(*this, other);
			}
		}
	}
	else if (this->m_isNegative && other.m_isNegative)
	{
		if (LessThanHelper(*this, other))
		{
			return MakeDifference(other, *this);
		}
		else
		{
			IntegerNumber aux = MakeDifference(*this, other);
			if (aux.m_dim == 1 && aux.m_v[1] == 0)
				aux.m_isNegative = false;
			else
				aux.m_isNegative = true;
			return aux;
		}
	}
	else if (this->m_isNegative && !other.m_isNegative)
	{
		IntegerNumber aux = MakeSum(*this, other);
		aux.m_isNegative = true;
		return aux;
	}
	//else
	return MakeSum(*this, other);
}

IntegerNumber MathLib::IntegerNumber::MakeProduct(IntegerNumber other) const
{
	IntegerNumber aux = MakeProduct(*this, other);
	if ((!this->m_isNegative && !other.m_isNegative) || (this->m_isNegative && other.m_isNegative))
		aux.m_isNegative = false;
	else
		aux.m_isNegative = true;
	return aux;
}

IntegerNumber MathLib::IntegerNumber::MakeDivision(IntegerNumber other) const
{
	IntegerNumber aux = MakeDivision(*this, other);
	if ((!this->m_isNegative && !other.m_isNegative) || (this->m_isNegative && other.m_isNegative))
		aux.m_isNegative = false;
	else
		aux.m_isNegative = true;
	return aux;
}

IntegerNumber MathLib::IntegerNumber::MakeModulo(IntegerNumber other) const
{
	return MakeModulo(*this, other);
}

void IntegerNumber::Print(ostream & out)
{
	if (!this->m_isValid)
		out << "NaN";
	else
	{
		if (this->m_isNegative)
			out << "-";
		for (int i = this->m_dim;i >= 1;--i)
			out << this->m_v[i];
	}
}

bool IntegerNumber::LessThanHelper(IntegerNumber x, IntegerNumber y)
{
	if (x.m_dim > y.m_dim)
		return false;
	else
	{
		if (x.m_dim < y.m_dim)
			return true;
		else
		{
			for (int i = x.m_dim;i >= 1;--i)
			{
				if (x.m_v[i] != y.m_v[i])
				{
					if (x.m_v[i] < y.m_v[i])
						return true;
					else
						return false;
				}
			}
			return false;
		}
	}
}

IntegerNumber IntegerNumber::MakeSum(IntegerNumber a, IntegerNumber b)
{
	IntegerNumber c(max(a.m_dim, b.m_dim) + 10);
	//c.m_v = new int[max(a.m_dim, b.m_dim) + 10];
	int i = 1, tr = 0, poz = 1;
	while (i <= a.m_dim && i <= b.m_dim)
	{
		c.m_v[poz] = (a.m_v[i] + b.m_v[i] + tr) % 10;
		tr = (a.m_v[i] + b.m_v[i] + tr) / 10;
		++i;
		++poz;
	}
	while (i <= a.m_dim)
	{
		c.m_v[poz] = (a.m_v[i] + tr) % 10;
		tr = (a.m_v[i] + tr) / 10;
		++i;
		++poz;
	}
	while (i <= b.m_dim)
	{
		c.m_v[poz] = (b.m_v[i] + tr) % 10;
		tr = (b.m_v[i] + tr) / 10;
		++i;
		++poz;
	}
	if (tr != 0)
		c.m_v[poz] = tr;
	else
		--poz;
	c.m_dim = poz;
	return c;
}

IntegerNumber IntegerNumber::MakeDifference(IntegerNumber a, IntegerNumber b)
{
	IntegerNumber c(max(a.m_dim, b.m_dim) + 10);
	int i = 1, j;
	while (i <= a.m_dim && i <= b.m_dim)
	{
		if (a.m_v[i] < b.m_v[i])
		{
			j = i + 1;
			while (a.m_v[j] == 0)
				++j;
			--a.m_v[j];
			--j;
			while (j >= i + 1)
			{
				a.m_v[j] = 9;
				--j;
			}
			a.m_v[i] += 10;
		}
		c.m_v[i] = a.m_v[i] - b.m_v[i];
		++i;
	}
	while (i <= a.m_dim)
	{
		c.m_v[i] = a.m_v[i];
		++i;
	}
	j = max(a.m_dim, b.m_dim) + 10 - 1;
	while (j >= 1 && c.m_v[j] == 0)
		--j;
	if (j == 0)
		j = 1;
	c.m_dim = j;
	return c;
}

IntegerNumber MathLib::IntegerNumber::MakeProduct(IntegerNumber a, IntegerNumber b)
{
	IntegerNumber c(a.m_dim + b.m_dim + 10);
	if ((a.m_v[1] == 0 & a.m_dim == 1) || (b.m_v[1] == 0 & b.m_dim == 1))
	{
		c.m_dim = 1;
		c.m_v[1] = 0;
		return c;
	}
	int i = 1, j = 1, poz = 0, tr1 = 0, tr2 = 0, k;
	for (j = 1;j <= b.m_dim;++j)
	{
		poz = j - 1;
		for (i = 1;i <= a.m_dim;++i)
		{
			tr1 += a.m_v[i] * b.m_v[j];
			c.m_v[++poz] += tr1 % 10;
			tr1 /= 10;
			if (c.m_v[poz] >= 10)
			{
				tr2 = c.m_v[poz];
				c.m_v[poz] = tr2 % 10;
				tr2 /= 10;
				k = poz + 1;
				while (tr2 > 0)
				{
					c.m_v[k] += tr2 % 10;
					++k;
					tr2 /= 10;
				}
			}
		}
		while (tr1 > 0)
		{
			tr1 += c.m_v[++poz];
			c.m_v[poz] = tr1 % 10;
			tr1 /= 10;
		}	
	}
	c.m_dim = poz;
	return c;
}

IntegerNumber MathLib::IntegerNumber::MakeDivision(IntegerNumber a, IntegerNumber b)
{
	IntegerNumber c(max(a.m_dim, b.m_dim) - min(a.m_dim, b.m_dim) + 10);
	int x = 0;
	for (int i = b.m_dim;i >= 1;--i)
		x = x * 10 + b.m_v[i];
	if (x == 0)
	{
		c.m_isValid = false;
		return c;
	}
	reverse(a.m_v + 1, a.m_v + a.m_dim + 1);
	int tr = 0, k = 0, aux, pos = 0;
	for (int i = 1;i <= a.m_dim;++i)
	{
		tr = tr * 10 + a.m_v[i];
		aux = tr / x;
		if (!(aux == 0 && k == 0))
			c.m_v[++pos] = aux;
		tr -= aux * x;
	}
	c.m_dim = pos;
	reverse(c.m_v + 1, c.m_v + c.m_dim + 1);
	return c;
}

IntegerNumber MathLib::IntegerNumber::MakeModulo(IntegerNumber a, IntegerNumber b)
{
	IntegerNumber c(max(a.m_dim, b.m_dim) - min(a.m_dim, b.m_dim) + 10);
	if (LessThanHelper(a, b))
	{
		c.m_dim = a.m_dim;
		c.m_isNegative = a.m_isNegative;
		for (int i = 1;i <= a.m_dim;++i)
			c.m_v[i] = a.m_v[i];
		return c;
	}
	int x = 0;
	for (int i = b.m_dim;i >= 1;--i)
		x = x * 10 + b.m_v[i];
	if (x == 0)
	{
		c.m_isValid = false;
		return c;
	}
	reverse(a.m_v + 1, a.m_v + a.m_dim + 1);
	int tr = 0, k = 0, aux, pos = 0;
	for (int i = 1;i <= a.m_dim;++i)
	{
		tr = tr * 10 + a.m_v[i];
		aux = tr / x;
		tr -= aux * x;
	}
	if (tr == 0)
		c.m_v[++pos] = 0;
	else while (tr > 0)
	{
		c.m_v[++pos] = tr % 10;
		tr /= 10;
	}
	c.m_dim = pos;
	reverse(c.m_v + 1, c.m_v + c.m_dim + 1);
	return c;
}

