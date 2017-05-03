#include "Matrix.h"
#include "Dijkstra.h"
#include <iostream>

int main()
{
	Matrix *matrix = new Matrix(5, 0 , 3);
	Dijkstra *dijkstra = new Dijkstra(*matrix);

	matrix->ReadFromFile();

	matrix->WriteMatrix();


	system("PAUSE");
	return 0;
}