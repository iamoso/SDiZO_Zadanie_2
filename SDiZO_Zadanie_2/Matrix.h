#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{
public:
	int **table;
	int size;

	Matrix(int length);
	~Matrix();
};

#endif