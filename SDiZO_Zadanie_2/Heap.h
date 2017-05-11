#ifndef HEAP_H
#define HEAP_H
#include <string>
#include <fstream>

using std::string;

class Heap
{
public:

	int *heapTable, size;

	Heap();
	~Heap();
	void SortHeapUp(int value);
	void SortHeapDown(int value);

	void Add(int data);

	void DeleteRoot();

	void WriteAll(string sp, string sn, int v);

	bool Search(int value);
};

#endif