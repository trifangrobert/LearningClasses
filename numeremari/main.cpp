#include <iostream>
#include <conio.h>

#include "IntegerNumber.h"
#include "DataStructures/Vector.h"
#include <vector>
#include <string>

#include <algorithm>
#include <fstream>

using namespace std;
using namespace MathLib;
using namespace DataStructures;

int main()
{
	Vector <char> v;
	v.Push_back('a');
	v.Push_back('b');
	v.Push_back('c');
	for (int i = 0;i < v.Size();++i)
		cout << v[i] << " ";
	_getch();

	return 0;
}
