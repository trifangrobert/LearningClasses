#ifdef VECTOR_H

#include <string>
#include <algorithm>
#include "Vector.h"

using namespace std;

namespace DataStructures
{
	template<typename T>
	Vector<T>::Vector()
	{
		this->m_v = new T[m_defaultSize];
		this->m_capacity = m_defaultSize;
		this->m_dim = 0;
	}

	template<typename T>
	Vector<T>::Vector(int n, T value)
	{
		this->m_v = new T[m_defaultSize];
		this->m_capacity = m_defaultSize;
		for (int i = 0;i < n;++i)
			this->Push_back(value);
	}

	template<typename T>
	Vector<T>::Vector(const Vector<T>& x)
	{
		this->m_v = new T[x.m_capacity];
		this->m_capacity = x.m_capacity;
		this->m_dim = x.m_dim;
		for (int i = 0;i < x.m_dim;++i)
			this->m_v[i] = x.m_v[i];
	}

	template<typename T>
	Vector<T>::~Vector()
	{
		delete[] this->m_v;
	}

	template<typename T>
	Vector<T>& Vector<T>::operator=(const Vector<T>& x)
	{
		delete[] this->m_v;
		this->m_v = new T[x.m_capacity];
		this->m_capacity = x.m_capacity;
		this->m_dim = x.m_dim;
		for (int i = 0;i < x.m_dim;++i)
			this->m_v[i] = x.m_v[i];
		return *this;
	}

	template<typename T>
	T & Vector<T>::operator[](int x)
	{
		return this->m_v[x];
	}

	template<typename T>
	void Vector<T>::Push_back(T x)
	{
		if (this->m_dim == this->m_capacity)
			IncreaseSize(*this);
		this->m_v[this->m_dim] = x;
		++this->m_dim;
	}

	template<typename T>
	void Vector<T>::Pop_back()
	{
		if (this->m_dim > 0)
			--this->m_dim;
		if (this->m_dim == this->m_capacity / 2)
			DecreaseSize(*this);
	}

	template<typename T>
	int Vector<T>::Size()
	{
		return this->m_dim;
	}

	template<typename T>
	int Vector<T>::GetDim()
	{
		return this->m_dim;
	}

	template<typename T>
	int Vector<T>::GetCapacity()
	{
		return this->m_capacity;
	}

	template<typename T>
	bool Vector<T>::Empty()
	{
		return this->m_dim == 0;
	}

	template<typename T>
	void Vector<T>::Insert(T x, int pos)
	{
		(*this).Push_back(x);
		for (int i = this->m_dim - 1;i > pos;--i)
			swap(this->m_v[i - 1], this->m_v[i]);
	}

	template<typename T>
	void Vector<T>::Erase(int pos)
	{
		for (int i = pos;i < this->m_dim - 1;++i)
			swap(this->m_v[i], this->m_v[i + 1]);
		(*this).Pop_back();
	}

	template<typename T>
	void Vector<T>::Clear()
	{
		delete[] this->m_v;
		this->m_dim = 0;

		this->m_v = new T[m_defaultSize];
		this->m_capacity = m_defaultSize;
	}

	template<typename T>
	void Vector<T>::Swap(Vector<T>& other)
	{
		swap(this->m_v, other.m_v);
		swap(this->m_dim, other.m_dim);
		swap(this->m_capacity, other.m_capacity);
	}

	template<typename T>
	void Vector<T>::Resize(int n, T value)
	{
		while (this->m_dim > n)
			this->Pop_back();
		while (this->m_dim < n)
			this->Push_back(value);
	}

	template<typename T>
	void Vector<T>::Reserve(int n)
	{
		if (n <= this->m_dim)
			return;
		while (this->m_capacity < n)
			IncreaseSize(*this);
	}

	template<typename T>
	T Vector<T>::Front()
	{
		if (this->m_dim == 0)
			throw runtime_error("Not enough elements!");
		return this->m_v[0];
	}

	template<typename T>
	T Vector<T>::Back()
	{
		if (this->m_dim == 0)
			throw runtime_error("Not enough elements!");
		return this->m_v[this->m_dim - 1];
	}

	template<typename T>
	T * Vector<T>::Begin()
	{
		return this->m_v;
	}

	template<typename T>
	T * Vector<T>::End()
	{
		return this->m_v + this->m_dim;
	}

	template<typename T>
	void Vector<T>::IncreaseSize(Vector<T>& x)
	{
		T *aux = new T[2 * x.m_capacity];
		for (int i = 0;i < x.m_capacity;++i)
			aux[i] = x.m_v[i];
		delete[] x.m_v;
		x.m_v = aux;
		x.m_capacity *= 2;
	}

	template<typename T>
	void Vector<T>::DecreaseSize(Vector<T>& x)
	{
		T *aux = new T[x.m_capacity / 2];
		for (int i = 0;i < x.m_capacity / 2;++i)
			aux[i] = x.m_v[i];
		delete[] x.m_v;
		x.m_v = aux;
		x.m_capacity /= 2;
	}
}

#endif 