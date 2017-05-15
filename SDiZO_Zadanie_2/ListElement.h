#ifndef LISTELEMENT_H
#define LISTELEMENT_H

class ListElement
{
public:
	ListElement();

	int vertex;
	int weight;
	ListElement *next, *prev;
};

#endif