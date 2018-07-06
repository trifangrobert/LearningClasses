#ifndef VECTOR_H
#define VECTOR_H
#include <string>

namespace DataStructures
{
	template<typename T> 
	class Vector
	{
	public:
		Vector();
		Vector(int n, T value = T());
		Vector(const Vector<T>& x);
		~Vector();

		Vector& operator=(const Vector<T>& x);
		T& operator[](int x);

		void Push_back(T x);
		void Pop_back();
		int Size();
		int GetDim();
		int GetCapacity();
		bool Empty();
		void Insert(T x, int pos);
		void Erase(int pos);
		void Clear();
		void Swap(Vector<T>& other);
		void Resize(int n, T value = T());
		void Reserve(int n);
		T Front();
		T Back();
		T* Begin();
		T* End();

	private:
		void IncreaseSize(Vector<T>& x);
		void DecreaseSize(Vector<T>& x);

		static const int m_defaultSize = 1;
		T* m_v;
		int m_capacity;
		int m_dim;
	};
}

#include "Vector.cpp"

#endif
