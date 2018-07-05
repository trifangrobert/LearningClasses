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

int a[10];

int main()
{
	ifstream fin("test.in");
	ofstream fout("test.out");
	Vector x;
	x.Push_back(1);
	x.Push_back(2);
	x.Push_back(3);
	x.Pop_back();
	for (int i = 0;i < x.Size();++i)
		cout << x.GetValue(i) << " ";
	try(x.Front())
	{
		catch 
	}
	_getch();
	return 0;
}
