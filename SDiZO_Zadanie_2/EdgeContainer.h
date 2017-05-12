#ifndef EEDGECONTAINER_H
#define EEDGECONTAINER_H
#include "Edge.h"

using namespace std;

class EdgeContainer
{
private:
	int size;
	Edge *table;

public:
	EdgeContainer();
	EdgeContainer(int size);
	~EdgeContainer();
	void AddAtTheBeginning(int sVertex, int eVertex, int dist);
	void AddAtTheEnd(int sVertex, int eVertex, int dist);
	void AddInRandomPlace(int sVertex, int eVertex, int dist, int place);

	void DeleteFromBeginning();
	void DeleteFromEnd();
	void DeleteFromRandomPlace(int place);

	void WriteAll();

	//int Search(int value);

	int GetSize();
};

#endif