#include "Matrix.h"
#include "Dijkstra.h"
#include "Kruskal.h"
#include <iostream>

int main()
{
	Matrix *matrix = new Matrix;

	matrix->ReadFromFile();

	matrix->WriteMatrix();
	
	//Dijkstra *dijkstra = new Dijkstra(*matrix);
	Kruskal *kruskal = new Kruskal(*matrix);


	//dijkstra->Run(*matrix);
	kruskal->Run(*matrix);
	cout << endl;

	system("PAUSE");
	return 0;
}