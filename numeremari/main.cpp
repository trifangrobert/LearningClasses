#include "IntegerNumber.h"
#include <vector>
#include <string>

#include <algorithm>
#include <fstream>

using namespace std;
using namespace MathLib;

string s1, s2;

int main()
{
	ifstream fin("test.in");
	ofstream fout("test.out");
	fin >> s1;
	fin >> s2;
	IntegerNumber x(s1);
	IntegerNumber y(s2);
	IntegerNumber z = x * y;
	z.Print(fout);
	fin.close();
	return 0;
}
