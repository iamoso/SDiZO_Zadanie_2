#include "Matrix.h"
#include "Dijkstra.h"
#include <iostream>

int main()
{
	Matrix *matrix = new Matrix(5, 0 , 3);
	Dijkstra *dijkstra = new Dijkstra(*matrix);

	for (int i = 0; i < matrix->size; i++)
	{
		for (int j = 0; j < matrix->size; j++)
		{
			cout << matrix->table[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < matrix->size; i++)
	{
		cout << dijkstra->dist[i] << " ";
	}

	cout << endl;

	cout << endl;
	cout << endl;

	delete matrix;
	matrix = new Matrix(6, 2, 5);
	delete dijkstra;
	dijkstra = new Dijkstra(*matrix);

	for (int i = 0; i < matrix->size; i++)
	{
		for (int j = 0; j < matrix->size; j++)
		{
			cout << matrix->table[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	cout << endl;

	for (int i = 0; i < matrix->size; i++)
	{
		cout << dijkstra->dist[i] << " ";
	}

	cout << endl;

	system("PAUSE");
	return 0;
}