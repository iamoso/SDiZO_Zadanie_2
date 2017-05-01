#include "Matrix.h"
#include "Dijkstra.h"
#include <iostream>

int main()
{
	Matrix matrix(5);
	Dijkstra dijkstra(matrix);

	for (int i = 0; i < matrix.size; i++)
	{
		for (int j = 0; j < matrix.size; j++)
		{
			cout << matrix.table[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	cout << endl;

	for (int i = 0; i < dijkstra.matrix.size; i++)
	{
		for (int j = 0; j < dijkstra.matrix.size; j++)
		{
			cout << dijkstra.matrix.table[i][j] << " ";
		}
		cout << endl;
	}

	system("PAUSE");
	return 0;
}