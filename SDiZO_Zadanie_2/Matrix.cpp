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

	FillWithInfinity();

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

void Matrix::FillWithInfinity()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			table[i][j] = numeric_limits<int>::max();
		}
	}
}

void Matrix::ReadFromFile(bool directed)
{
	string fileName;
	cout << "Podaj nazwe pliku: ";
	cin >> fileName;
	fstream file(fileName, ios_base::in);
	int x , y, weight;

	if (file.good())
	{
		if (table)
		{
			for (int i = 0; i < size; i++)
			{
				delete[] table[i];
			}
			delete[] table;
		}

		file >> numberOfEdges >> size >> startVertex >> endVertex;

		table = new int *[size];

		for (int i = 0; i < size; i++)
		{
			table[i] = new int[size];
		}

		FillWithInfinity();

		for (int i = 0; i < numberOfEdges; i++)
		{
			file >> x >> y >> weight;
			table[x][y] = weight;
			if (!directed)
			{
				table[y][x] = weight;
			}
		}

		file.close();
	}
}

void Matrix::ReadFromFile(string fileName, bool directed)
{
	fstream file(fileName, ios_base::in);
	int x, y, weight;

	if (file.good())
	{
		if (table)
		{
			for (int i = 0; i < size; i++)
			{
				delete[] table[i];
			}
			delete[] table;
		}

		file >> numberOfEdges >> size >> startVertex >> endVertex;

		table = new int *[size];

		for (int i = 0; i < size; i++)
		{
			table[i] = new int[size];
		}

		FillWithInfinity();

		for (int i = 0; i < numberOfEdges; i++)
		{
			file >> x >> y >> weight;
			table[x][y] = weight;
			if (!directed)
			{
				table[y][x] = weight;
			}
		}

		file.close();
	}
}

void Matrix::WriteMatrix()
{
	cout << setw(11) << "";
	for (int i = 0; i < size; i++)
	{
		cout << setw(10) << i << " ";
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << setw(10) << i << " ";
		for (int j = 0; j < size; j++)
		{
			cout << setw(10) << table[i][j] << " ";
		}
		cout << endl;
	}
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
