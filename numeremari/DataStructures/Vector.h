#pragma once

#include <string>

namespace DataStructures
{
	class Vector
	{
	public:
		Vector();
		Vector(int n, int value = 0);

		void operator=(Vector x);

		void Push_back(int x);
		void Pop_back();
		int Size();
		int GetValue(int pos);
		int GetDim();
		int GetCapacity();
		bool Empty();
		void Insert(int x, int pos);
		void Erase(int pos);
		void Clear();
		void Swap(Vector &other);
		void Resize(int n, int value = 0);
		void Reserve(int n);
		int Front();
		int Back();
		int* Begin();
		int* End();

	private:
		void IncreaseSize(Vector &x);
		void DecreaseSize(Vector &x);

		int *m_v;
		int m_capacity;
		int m_dim;
	};
}
