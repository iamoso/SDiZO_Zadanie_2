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
	Matrix *undirected = new Matrix;
	Matrix *directed = new Matrix;

	Table *directedTable = new Table;
	Table *undirectedTable = new Table;

	undirected->ReadFromFile(false);
	undirected->WriteMatrix();

	undirectedTable->ReadFromFile(false);
	/*
	directed->ReadFromFile(true);
	//directed->WriteMatrix();

	directedTable->ReadFromFile(true);


	BellmanFord *bellmanFord = new BellmanFord(*directed);

	t = bellmanFord->Run(*directed);

	cout << t << endl;

	BellmanFord *bellmanFordTable = new BellmanFord(*directedTable);

	t = bellmanFordTable->Run(*directedTable);

	cout << t << endl;
	*/
	/*if (0 > numeric_limits<int>::max() + 2)
	{
		cout << "If entered";
	}
	else
		cout << "not.";*/

	//cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

	//Dijkstra *dijkstra = new Dijkstra(*directed);
	//Dijkstra *dijkstraTable = new Dijkstra(*directedTable);
	Kruskal *kruskal = new Kruskal(*undirected);
	Kruskal *kruskalTable = new Kruskal(*undirectedTable);
	//Prim *prim = new Prim(*undirected);

	//dijkstra->write(*directedTable);

	//dijkstra->Run(*directed);
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	//dijkstraTable->Run(*directedTable);

	kruskal->Run(*undirected);
	cout << "////////////////////////////////////////" << endl;
	kruskalTable->Run(*undirectedTable);
	//prim->Run(*undirected);
	//cout << endl;

	

	system("PAUSE");
	return 0;
}