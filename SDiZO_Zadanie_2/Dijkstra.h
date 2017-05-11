#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "Matrix.h"
#include "Heap.h"
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
	~Dijkstra();

	void Run(Matrix &matrix);

	void AddToTable(int data, int currentSize);
};

#endif