#ifndef HEAP_H
#define HEAP_H
#include "Edge.h"
#include <iostream>
#include <string>

using namespace std;

class Heap
{
public:

	int size;

	Edge *heapTable;

	Heap();
	~Heap();
	void SortHeapUp(Edge value);
	void SortHeapDown(Edge value);

	void Add(int sVertex, int eVertex, int dist);

	void Pop();

	void WriteAll(string sp, string sn, int v);

	Edge Front();
};

#endif