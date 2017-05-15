#ifndef LIST_H
#define LIST_H
#include "ListElement.h"


class List
{
public:
	int size;
	ListElement *head, *tail;

	List();
	~List();
	void AddAtTheBeginning(int data, int eWeight);
	void AddAtTheEnd(int data, int eWeight);
	void AddInRandomPlace(int data, int place, int eWeight);

	void DeleteFromBeginning();
	void DeleteFromEnd();
	void DeleteFromRandomPlace(int place);

	void WriteAll();

	int Search(int value);
};

#endif