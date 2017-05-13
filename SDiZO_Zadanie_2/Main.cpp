#include "Matrix.h"
#include "Dijkstra.h"
#include "Kruskal.h"
#include "Prim.h"
#include <iostream>

int main()
{
	Matrix *undirected= new Matrix;

	undirected->ReadFromFile(false);

	undirected->WriteMatrix();
	
	//Dijkstra *dijkstra = new Dijkstra(*matrix);
	//Kruskal *kruskal = new Kruskal(*matrix);
	Prim *prim = new Prim(*undirected);


	//dijkstra->Run(*matrix);
	//kruskal->Run(*matrix);
	prim->Run(*undirected);
	cout << endl;

	system("PAUSE");
	return 0;
}