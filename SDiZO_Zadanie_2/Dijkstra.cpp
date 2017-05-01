#include "Dijkstra.h"

Dijkstra::Dijkstra(Matrix &matrix)
{
	dist = new int[matrix.size];
	prev = new int[matrix.size];
	collectionQS = new bool[matrix.size];

	for (int i = 0; i < matrix.size; i++)
	{
		dist[i] = numeric_limits<int>::max();
		prev[i] = -1;
		collectionQS[i] = false;
	}
	dist[matrix.startVertex] = 0;
}

Dijkstra::~Dijkstra()
{
	delete[] dist;
	delete[] prev;
	delete[] collectionQS;
}
