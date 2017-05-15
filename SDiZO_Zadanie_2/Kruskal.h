#ifndef KRUSKAL_H
#define KRUSKAL_H
#include "Matrix.h"
#include "Table.h"
#include "Heap.h"
#include "EdgeContainer.h"

using namespace std;

class Kruskal
{
public:
	int *set;
	Heap queue;
	EdgeContainer edges;
	
	Kruskal(Matrix &matrix);
	Kruskal(Table &tab);
	~Kruskal();

	void Run(Matrix &matrix);
	void Run(Table &tab);
};

#endif