#ifndef PRIM_H
#define PRIM_H
#include "Matrix.h"
#include "Table.h"
#include "Heap.h"
#include "EdgeContainer.h"

using namespace std;

class Prim
{
public:
	int vertex;
	bool *visited;
	Heap queue;
	EdgeContainer edges;

	Prim(Matrix &matrix);
	Prim(Table &tab);
	~Prim();

	void Run(Matrix &matrix);
	void Run(Table &tab);
};

#endif