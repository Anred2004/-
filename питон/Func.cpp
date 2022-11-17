#include "Func.hpp"


namespace pp
{
	void Read(int& n, int& m, int matrix[100][100])
	{
		//std::cin >> n;
		//std::cin >> m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				std::cin >> matrix[i][j];

			}

		}

	}
	void Write(int n, int m, int matrix[100][100])
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				std::cout << matrix[i][j] << " ";

			}
			std::cout << endl;

		}
	}
	bool isPrime(int m, int mas[100])
	{

		for (int j = 0; j < m; j++)
		{
			bool flag = true;
			if (mas[j] < 2)
			{
				flag = false;
			}
			for (int d = 2; d <= sqrt(mas[j]); d++)
			{
				if (mas[j] % d == 0)
				{
					flag = false;
				}

			}
			if (flag) return true;
		}
		return false;
	}
	bool isPrime1(int m, int mas[100])
	{
		int sum = 0;
		for (int j = 0; j < m; j++)
		{
			sum += mas[j];
		}
		if (sum == 0)
		{
			return true;
		}
		return false;
	}

	bool check(int m, int n, int matrix[100][100])
	{
		for (int i = 0; i < n; i++)
		{
			if (isPrime(m, matrix[i]) && isPrime1(m, matrix[i]))
				return true;
		}
		return false;
	}

	int findnorm(int sumnorm[100], int n)
	{
		int summ = 0;
		for (int i = 0; i < n; i++)
		{
			summ += sumnorm[i] * sumnorm[i];

		}
		return sqrt(summ);
	}

	void sort(int m, int n, int matrix[100][100])
	{
		if (check(m, n, matrix))
		{
			int norm[100];
			for (int j = 0; j < m; j++)
			{
				int stolb[100];
				for (int k = 0; k < n; k++)
				{
					stolb[k] = matrix[k][j];
				}
				norm[j] = findnorm(stolb, n);
			}
			for (int i = 0; i < m - 1; i++)
			{
				for (int j = i + 1; j < m; j++)
				{
					if (norm[i] < norm[j])
					{
						swap(norm[i], norm[j]);
						for (int k = 0; k < n; k++)
						{
							swap(matrix[k][i], matrix[k][j]);

						}
					}
				}
			}
		}
	}




}