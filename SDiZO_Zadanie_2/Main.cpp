#include "Matrix.h"
#include "Dijkstra.h"
#include <iostream>

int main()
{
	Matrix *matrix = new Matrix;

	matrix->ReadFromFile();

	matrix->WriteMatrix();
	
	Dijkstra *dijkstra = new Dijkstra(*matrix);

	dijkstra->Run(*matrix);
	
	cout << endl;

	system("PAUSE");
	return 0;
}