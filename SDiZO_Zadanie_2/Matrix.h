#ifndef MATRIX_H
#define MATRIX_H
#include <limits>

using namespace std;

class Matrix
{
public:
	int **table;
	int size;
	int startVertex;
	int endVertex;

	Matrix();
	Matrix(int length, int sVertex, int eVertex);
	~Matrix();

	//Matrix & operator=(Matrix &pattern);
};

#endif