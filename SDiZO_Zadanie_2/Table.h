#ifndef TABLE_H
#define TABLE_H
#include "List.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Table
{
public:
	int size;
	int numberOfEdges;
	int startVertex;
	int endVertex;
	List *table;

	Table();
	Table(int size);
	~Table();
	void AddAtTheBeginning(List data);
	void AddAtTheEnd(List data);
	void AddInRandomPlace(List data, int place);

	void DeleteFromBeginning();
	void DeleteFromEnd();
	void DeleteFromRandomPlace(int place);

	void ReadFromFile(bool directed);

	void WriteAll();

	//int Search(int value);

	//int GetSize();
};

#endif