#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "Matrix.h"
#include "Table.h"
#include <limits>

using namespace std;

class Dijkstra
{
public:
	int *dist;
	int *prev;
	int *neighbours;
	int numberOfNeighbours;

	bool *collectionQS;

	Dijkstra(Matrix &matrix);
	Dijkstra(Table &tab);
	~Dijkstra();

	void Run(Matrix &matrix);
	void Run(Table &tab);

	void write(Table &tab);

	void AddToTable(int data, int currentSize);
};

#endif