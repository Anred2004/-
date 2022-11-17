#include <iostream>
#include <fstream>
using namespace std;
namespace pp
{
	void Read(int& n, int& m, int matrix[100][100]);
	bool isPrime(int m, int mas[100]);
	bool isPrime1(int m, int mas[100]);
	bool check(int m, int n, int matrix[100][100]);
	int findnorm(int sumnorm[100], int n);
	void sort(int m, int n, int matrix[100][100]);
	void Write(int n, int m, int matrix[100][100]);
}
