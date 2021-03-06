#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Matrix
{
public:
	int **table;
	int size;
	int numberOfEdges;
	int startVertex;
	int endVertex;

	Matrix();
	Matrix(int length, int sVertex, int eVertex);
	~Matrix();

	void FillWithInfinity();
	void ReadFromFile(bool directed);
	void ReadFromFile(string fileName, bool directed);
	void WriteMatrix();

	//Matrix & operator=(Matrix &pattern);
};

#endif