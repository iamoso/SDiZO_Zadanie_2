#ifndef KRUSKAL_H
#define KRUSKAL_H
#include "Matrix.h"
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
	~Kruskal();

	void Run(Matrix &matrix);
};

#endif