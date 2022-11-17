#include <iostream>
#include "Func.hpp"

int main()
{
	int m, n;
	std::cin >> n;
	std::cin >> m;
	int matrix[100][100];
	pp::Read(n, m, matrix);
	pp::sort(m, n, matrix);
	pp::Write(n, m, matrix);
}