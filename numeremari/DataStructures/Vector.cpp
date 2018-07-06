#define SIZE 1

#include <string>
#include <algorithm>
#include "Vector.h"

using namespace DataStructures;
using namespace std;

DataStructures::Vector::Vector()
{
	this->m_v = new int[SIZE];
	this->m_capacity = SIZE;
	this->m_dim = 0;
}

DataStructures::Vector::Vector(int n, int value)
{
	this->m_v = new int[SIZE];
	this->m_capacity = SIZE;
	while (this->m_capacity < n)
		IncreaseSize(*this);
	this->m_dim = n;
	for (int i = 0;i < this->m_dim;++i)
		this->m_v[i] = value;
}

DataStructures::Vector::~Vector()
{
	delete[] this->m_v;
}

void DataStructures::Vector::operator=(Vector x)
{
	delete[] this->m_v;
	this->m_capacity = x.m_capacity;
	this->m_dim = x.m_dim;
	for (int i = 0;i < x.m_dim;++i)
		this->m_v[i] = x.m_v[i];
}

int & DataStructures::Vector::operator[](int x)
{
	return this->m_v[x];
}

void Vector::Push_back(int x)
{
	if (this->m_dim == this->m_capacity)
		IncreaseSize(*this);
	this->m_v[this->m_dim] = x;
	++this->m_dim;
}

void Vector::Pop_back()
{
	if (this->m_dim > 0)
		--this->m_dim;
	if (this->m_dim == this->m_capacity / 2)
		DecreaseSize(*this);
}

int Vector::Size()
{
	return this->m_dim;
}

int Vector::GetValue(int pos)
{
	return this->m_v[pos];
}

int DataStructures::Vector::GetDim()
{
	return this->m_dim;
}

int DataStructures::Vector::GetCapacity()
{
	return this->m_capacity;
}

bool DataStructures::Vector::Empty()
{
	return this->m_dim == 0;
}

void DataStructures::Vector::Insert(int x, int pos)
{
	(*this).Push_back(x);
	for (int i = this->m_dim - 1;i > pos;--i)
		swap(this->m_v[i - 1], this->m_v[i]);
}

void DataStructures::Vector::Erase(int pos)
{
	for (int i = pos;i < this->m_dim - 1;++i)
		swap(this->m_v[i], this->m_v[i + 1]);
	(*this).Pop_back();
}

void DataStructures::Vector::Clear()
{
	delete[] this->m_v;
	this->m_dim = 0;
	this->m_v = new int[SIZE];
	this->m_capacity = SIZE;
}

void DataStructures::Vector::Swap(Vector &other)
{
	Vector aux;
	aux.m_v = new int[this->m_capacity];

	for (int i = 0;i < this->m_dim;++i)
		aux.m_v[i] = this->m_v[i];
	aux.m_capacity = this->m_capacity;
	aux.m_dim = this->m_dim;

	delete[] this->m_v;
	this->m_v = new int[other.m_capacity];
	this->m_dim = other.m_dim;
	this->m_capacity = other.m_capacity;

	for (int i = 0;i < other.m_dim;++i)
		this->m_v[i] = other.m_v[i];

	delete[] other.m_v;
	other.m_v = new int[aux.m_capacity];
	other.m_dim = aux.m_dim;
	other.m_capacity = aux.m_capacity;

	for (int i = 0;i < aux.m_dim;++i)
		other.m_v[i] = aux.m_v[i];

	delete[] aux.m_v;
}

void DataStructures::Vector::Resize(int n, int value)
{
	if (n == this->m_dim)
		return;
	if (n < this->m_dim)
	{
		while (n <= this->m_capacity / 2 && this->m_capacity > SIZE)
			DecreaseSize(*this);
		this->m_dim = n;
	}
	else
	{
		while (this->m_capacity < n)
			IncreaseSize(*this);
		for (int i = this->m_dim;i < n;++i)
			this->m_v[i] = value;
		this->m_dim = n;
	}
}

void DataStructures::Vector::Reserve(int n)
{
	if (n <= this->m_dim)
		return;
	while (this->m_capacity < n)
		IncreaseSize(*this);
}

int DataStructures::Vector::Front()
{
	//daca this->m_dim == 0 => eroare
	return this->m_v[0];
}

int DataStructures::Vector::Back()
{
	//daca this->m_dim == 0 => eroare
	return this->m_v[this->m_dim - 1];
}

int * DataStructures::Vector::Begin()
{
	return this->m_v;
}

int * DataStructures::Vector::End()
{
	return this->m_v + this->m_dim;
}

void DataStructures::Vector::IncreaseSize(Vector &x)
{
	int *aux = new int[2 * x.m_capacity];
	for (int i = 0;i < x.m_capacity;++i)
		aux[i] = x.m_v[i];
	delete[] x.m_v;
	x.m_v = new int[2 * x.m_capacity];
	x.m_capacity *= 2;
	for (int i = 0;i < x.m_capacity;++i)
		x.m_v[i] = aux[i];
	delete[] aux;
}

void DataStructures::Vector::DecreaseSize(Vector &x)
{
	int *aux = new int[x.m_capacity / 2];
	for (int i = 0;i < x.m_capacity / 2;++i)
		aux[i] = x.m_v[i];
	delete[] x.m_v;
	x.m_v = new int[x.m_capacity / 2];
	x.m_capacity /= 2;
	for (int i = 0;i < x.m_capacity;++i)
		x.m_v[i] = aux[i];
	delete[] aux;
}

