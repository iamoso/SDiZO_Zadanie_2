#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "Matrix.h"
#include <limits>

using namespace std;

class Dijkstra
{
public:
	int *dist;
	int *prev;

	bool *collectionQS;

	Dijkstra(Matrix &matrix);
	~Dijkstra();
};

#endif