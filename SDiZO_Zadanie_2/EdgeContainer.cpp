#include "EdgeContainer.h"


EdgeContainer::EdgeContainer()
{
	size = 0;
	table = new Edge[0];
}

EdgeContainer::EdgeContainer(int size)
{
	size = size;
	table = new Edge[size];
}

EdgeContainer::~EdgeContainer()
{
	delete[] table;
}

void EdgeContainer::AddAtTheBeginning(int sVertex, int eVertex, int dist)
{
	Edge *temp = new Edge[size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = table[i];
	}
	delete[] table;
	table = new Edge[size + 1];
	table[size].startVertex = sVertex;
	table[size].endVertex = eVertex;
	table[size].distance = dist;
	for (int i = 0; i < size; i++)
	{
		table[i + 1] = temp[i];
	}
	size++;
	delete[] temp;
}

void EdgeContainer::AddAtTheEnd(int sVertex, int eVertex, int dist)
{
	Edge *temp = table;
	table = new Edge[size + 1];
	for (int i = 0; i < size; i++)
	{
		table[i] = temp[i];
	}
	table[size].startVertex = sVertex;
	table[size].endVertex = eVertex;
	table[size].distance = dist;
	size++;
	delete[] temp;
}

void EdgeContainer::AddInRandomPlace(int sVertex, int eVertex, int dist, int place)
{
	if (place == 0)
	{
		AddAtTheBeginning(sVertex, eVertex, dist);
	}
	else if (place == size)
	{
		AddAtTheEnd(sVertex, eVertex, dist);
	}
	else if (place < 0 || place > size)
	{
		cout << "Niepoprawne miejsce do wstawienia danej." << endl;
	}
	else
	{
		Edge *temp = table;
		table = new Edge[size + 1];
		for (int i = 0; i < place; i++)
		{
			table[i] = temp[i];
		}
		table[size].startVertex = sVertex;
		table[size].endVertex = eVertex;
		table[size].distance = dist;
		for (int i = place; i < size; i++)
		{
			table[i + 1] = temp[i];
		}
		size++;
		delete[] temp;
	}
}

void EdgeContainer::DeleteFromBeginning()
{
	if (size == 0)
	{
		cout << "Tablica jest juz pusta." << endl;
	}
	else
	{
		Edge *temp = new Edge[size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = table[i];
		}
		size--;
		delete[] table;
		table = new Edge[size];
		for (int i = 0; i < size; i++)
		{
			table[i] = temp[i + 1];
		}
		delete[] temp;
	}
}

void EdgeContainer::DeleteFromEnd()
{
	if (size == 0)
	{
		cout << "Tablica jest juz pusta." << endl;
	}
	else
	{
		Edge *temp = table;
		size--;
		table = new Edge[size];
		for (int i = 0; i < size; i++)
		{
			table[i] = temp[i];
		}
		delete[] temp;
	}
}

void EdgeContainer::DeleteFromRandomPlace(int place)
{
	if (size == 0)
	{
		cout << "Tablica jest juz pusta." << endl;
	}
	else
	{
		if (place >= size || place < 0)
		{
			cout << "Blednie wprowadzone dane." << endl;
		}
		else
		{
			Edge *temp = new Edge[size];
			for (int i = 0; i < size; i++)
			{
				temp[i] = table[i];
			}
			size--;
			delete[] table;
			table = new Edge[size];
			for (int i = 0; i < place; i++)
			{
				table[i] = temp[i];
			}
			for (int i = place; i < size; i++)
			{
				table[i] = temp[i + 1];
			}
			delete[] temp;
		}
	}
}

void EdgeContainer::WriteAll()
{
	for (int i = 0; i < size; i++)
	{
		cout << "(" << table[i].startVertex << ", " << table[i].endVertex << ")    " << table[i].distance << endl;
	}
}
/*
int EdgeContainer::Search(int value)
{
	for (int i = 0; i < size; i++)
	{
		if (table[i] == value)
			return i;
	}
	return -1;
}
*/
int EdgeContainer::GetSize()
{
	return size;
}

