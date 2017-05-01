#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "Matrix.h"
#include <limits>

using namespace std;

class Dijkstra
{
public:
	Matrix matrix;
	int **table;
	int size;
	int startVertex;
	int endVertex;

	int *dist;
	int *prev;

	bool *collectionQS;

	Dijkstra(Matrix &pattern);
	~Dijkstra();
};

#endif