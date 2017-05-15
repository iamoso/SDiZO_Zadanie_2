#include "Matrix.h"
#include "Table.h"
#include "Dijkstra.h"
#include "BellmanFord.h"
#include "Kruskal.h"
#include "Prim.h"
#include <iostream>

int main()
{
	//bool t;
	//Matrix *undirected = new Matrix;
	Matrix *directed = new Matrix;

	Table *directedTable = new Table;

	//undirected->ReadFromFile(false);
	//undirected->WriteMatrix();

	directed->ReadFromFile(true);
	//directed->WriteMatrix();

	directedTable->ReadFromFile(true);


	//BellmanFord *bellmanFord = new BellmanFord(*directed);

	//t = bellmanFord->Run(*directed);
	
	/*if (0 > numeric_limits<int>::max() + 2)
	{
		cout << "If entered";
	}
	else
		cout << "not.";*/

	//cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

	Dijkstra *dijkstra = new Dijkstra(*directed);
	Dijkstra *dijkstraTable = new Dijkstra(*directedTable);
	//Kruskal *kruskal = new Kruskal(*matrix);
	//Prim *prim = new Prim(*undirected);

	//dijkstra->write(*directedTable);

	dijkstra->Run(*directed);
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	dijkstraTable->Run(*directedTable);

	//kruskal->Run(*matrix);
	//prim->Run(*undirected);
	//cout << endl;

	//cout << t << endl;

	system("PAUSE");
	return 0;
}