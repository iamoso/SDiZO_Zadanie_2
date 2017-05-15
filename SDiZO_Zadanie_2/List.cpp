#include "List.h"
#include "ListElement.h"
#include <iostream>

using std::cout;
using std::endl;

List::List()
{
	size = 0;
	head = NULL;
	tail = NULL;
}

List::~List()
{
	ListElement *temp = tail;
	while (size != 0)
	{
		temp = tail->prev;
		delete tail;
		tail = temp;
		size--;
	}
	delete temp;
}

void List::AddAtTheBeginning(int data, int eWeight)
{
	ListElement *newElement = new ListElement;

	newElement->vertex = data;
	newElement->weight = eWeight;
	newElement->next = head;
	if (head)
	{
		head->prev = newElement;
	}
	head = newElement;
	if (size == 0)
	{
		tail = head;
	}
	size++;
}

void List::AddAtTheEnd(int data, int eWeight)
{
	ListElement *newElement = new ListElement();
	if (size != 0)
	{
		newElement->vertex = data;
		newElement->weight = eWeight;
		newElement->prev = tail;
		tail->next = newElement;
		tail = newElement;
		newElement->next = NULL;
		size++;
	}
	else
	{
		AddAtTheBeginning(data, eWeight);
	}
}

void List::AddInRandomPlace(int data, int place, int eWeight)
{
	if (place == 0)
	{
		AddAtTheBeginning(data, eWeight);
	}
	else if (place == size)
	{
		AddAtTheEnd(data, eWeight);
	}
	else if (place < 0 || place > size)
	{
		cout << "Niepoprawne miejsce do wstawienia danej." << endl;
	}
	else
	{
		ListElement *newElement = new ListElement;
		ListElement *temp = head;
		for (int i = 0; i < place; i++)
		{
			temp = temp->next;
		}
		newElement->vertex = data;
		newElement->weight = eWeight;
		newElement->next = temp;
		newElement->prev = temp->prev;
		temp->prev->next = newElement;
		temp->prev = newElement;
		size++;
	}
}

void List::DeleteFromBeginning()
{
	if (size == 0)
	{
		cout << "Lista jest juz pusta." << endl;
	}
	else
	{
		if (size > 1)
		{
			ListElement *temp = head->next;
			delete head;
			head = temp;
			head->prev = NULL;
		}
		else if (size == 1)
		{
			delete head;
			head = NULL;
			tail = NULL;
		}
		size--;
	}
}

void List::DeleteFromEnd()
{
	if (size == 0)
	{
		cout << "Lista jest juz pusta." << endl;
	}
	else
	{
		if (size > 1)
		{
			ListElement *temp = tail->prev;
			delete tail;
			tail = temp;
			tail->next = NULL;
		}
		else if (size == 1)
		{
			delete tail;
			head = NULL;
			tail = NULL;
		}
		size--;
	}
}

void List::DeleteFromRandomPlace(int place)
{
	if (size == 0)
	{
		cout << "Lista jest juz pusta." << endl;
	}
	else
	{
		if (place >= size || place < 0)
		{
			cout << "Blednie wprowadzone dane." << endl;
		}
		else if (place == 0)
		{
			DeleteFromBeginning();
		}
		else if (place == (size - 1))
		{
			DeleteFromEnd();
		}
		else
		{
			ListElement *temp = head;
			for (int i = 0; i < place; i++)
			{
				temp = temp->next;
			}
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			delete temp;
			size--;
		}
	}
}

void List::WriteAll()
{
	ListElement *temp = head;

	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
		{
			cout << "(" << temp->vertex << ", " << temp->weight << ") ";
		}
		else
		{
			cout << "(" << temp->vertex << ", " << temp->weight << ") ";
			temp = temp->next;
		}
	}

	cout << endl;
}

int List::Search(int value)
{
	ListElement *temp = head;
	for (int i = 0; i < size; i++)
	{
		if (temp->vertex == value)
			return i;
		temp = temp->next;
	}
	return -1;
}
