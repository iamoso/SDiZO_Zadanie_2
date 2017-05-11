#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <string>

using namespace std;

class Heap
{
public:

	int size;

	class Edge
	{
	public:
		int startVertex;
		int endVertex;
		int distance;
	};

	Edge *heapTable;

	Heap();
	~Heap();
	void SortHeapUp(Edge value);
	void SortHeapDown(Edge value);

	void Add(int sVertex, int eVertex, int dist);

	void DeleteRoot();

	void WriteAll(string sp, string sn, int v);

};

#endif