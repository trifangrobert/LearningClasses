#include <iostream>
#include "IntegerNumber.h"
#include <conio.h>
#include <vector>

#include <algorithm>
#include <fstream>
#define DIM 100

using namespace std;
using namespace MathLib;

char s1[DIM], s2[DIM];

void Read()
{
	ifstream f("test.in");
	f.getline(s1, DIM);
	f.getline(s2, DIM);
	f.close();
}

int main()
{
	Read();
	IntegerNumber x(s1);
	IntegerNumber y(s2);
	ofstream fout("test.out");
	IntegerNumber z = x * y;
	z.Print(cout);
	_getch();
	return 0;
}
