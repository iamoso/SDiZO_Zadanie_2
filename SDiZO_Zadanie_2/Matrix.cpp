#include "Matrix.h"

Matrix::Matrix(int length)
{
	size = length;
	table = new int *[size];
	for (int i = 0; i < size; i++)
	{
		table[i] = new int[size];
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
