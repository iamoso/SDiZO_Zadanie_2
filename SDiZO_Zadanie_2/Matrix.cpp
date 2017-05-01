#include "Matrix.h"

Matrix::Matrix()
{
	size = 0;
	table = NULL;
}

Matrix::Matrix(int length, int sVertex, int eVertex)
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

	startVertex = sVertex;
	endVertex = eVertex;
}

Matrix::~Matrix()
{
	for (int i = 0; i < size; i++)
	{
		delete[] table[i];
	}
	delete[] table;
	size = 0;
}

/*Matrix & Matrix::operator=(Matrix & pattern)
{
	size = pattern.size;
	table = new int *[size];
	for (int i = 0; i < size; i++)
	{
		table[i] = new int[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			table[i][j] = pattern.table[i][j];
		}
	}

	return *this;
}*/
