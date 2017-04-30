#include "Matrix.h"

Matrix::Matrix()
{
	size = 0;
	table = NULL;
}

Matrix::Matrix(int length)
{
	size = length;
	table = new int *[size];
	for (int i = 0; i < size; i++)
	{
		table[i] = new int[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			table[i][j] = numeric_limits<int>::max();
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < size; i++)
	{
		delete[] table[i];
	}
	delete[] table;
}
