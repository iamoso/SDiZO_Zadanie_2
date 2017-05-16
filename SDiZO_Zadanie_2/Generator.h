#ifndef GENERATOR_H
#define GENERATOR_H
#include "Matrix.h"
#include <fstream>
#include <iostream>

using namespace std;

class Generator
{
public:
	Matrix *matrix;

	void generateGraph(int numberOfVerticies, int density);

	void WriteToFile();
};

#endif