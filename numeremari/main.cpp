#include <iostream>
#include "IntegerNumber.h"
#include <conio.h>

#include <algorithm>
#include <fstream>
#define DIM 100 // am pus asa la misto :)
///o sa bag cu alocare dinamica

using namespace std;
using namespace MathLib;

char s1[DIM], s2[DIM];
int a[DIM], b[DIM], c[DIM];
bool ok;

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
	IntegerNumber z = x % y;
	z.Print(cout);
	_getch();
	return 0;
}
