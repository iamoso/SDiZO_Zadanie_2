#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <limits>
#include <fstream>
#include <string>

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

	void ReadFromFile();

	//Matrix & operator=(Matrix &pattern);
};

#endif