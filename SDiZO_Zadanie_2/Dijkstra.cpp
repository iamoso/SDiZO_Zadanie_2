#include "Dijkstra.h"

Dijkstra::Dijkstra(Matrix &pattern)
{
	//size = matrix.size;
	//table = matrix.table;
	//for (int i = 0; i < size; i++)
	//{
	//	table[i] = matrix.table[i];
	//}
	matrix = pattern;

	dist = new int[size];
	prev = new int[size];
	collectionQS = new bool[size];

	for (int i = 0; i < size; i++)
	{
		dist[i] = numeric_limits<int>::max();
		prev[i] = -1;
		collectionQS[i] = false;
	}
	dist[startVertex] = 0;
}

Dijkstra::~Dijkstra()
{
	for (int i = 0; i < size; i++)
	{
		table[i] = NULL;
	}
	table = NULL;
	size = 0;
}
