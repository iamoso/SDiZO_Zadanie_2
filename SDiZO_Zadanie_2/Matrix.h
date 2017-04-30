#ifndef MATRIX_H
#define MATRIX_H
#include <limits>

using namespace std;

class Matrix
{
public:
	int **table;
	int size;

	Matrix();
	Matrix(int length);
	~Matrix();
};

#endif