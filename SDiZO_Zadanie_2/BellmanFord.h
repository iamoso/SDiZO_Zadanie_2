#ifndef BELLMANFORD_H
#define BELLMANFORD_H
#include "Matrix.h"
#include "Table.h"
#include <limits>
#include <cmath>

using namespace std;

class BellmanFord
{
public:
	int *dist;
	int *prev;
	int *neighbours;
	int numberOfNeighbours;

	bool test;

	BellmanFord(Matrix &matrix);
	BellmanFord(Table &tab);
	~BellmanFord();

	bool Run(Matrix &matrix);
	bool Run(Table &tab);

	void AddToTable(int data, int currentSize);
};

#endif