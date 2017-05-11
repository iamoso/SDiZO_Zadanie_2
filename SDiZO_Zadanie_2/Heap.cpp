#include "Heap.h"
#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ios;

Heap::Heap()
{
	size = 0;
	heapTable = NULL;
}

Heap::~Heap()
{
	size = 0;
	delete[] heapTable;
}

void Heap::SortHeapUp(int value)
{
	int i, j;

	i = size - 1;
	j = (size - 1) / 2;
	while (i > 0 && heapTable[j] < value)
	{
		heapTable[i] = heapTable[j];
		i = j;
		j = (i - 1) / 2;
	}
	heapTable[i] = value;
}

void Heap::SortHeapDown(int value)
{
	int i = 0;
	int j = 1;
	while (j < size)
	{
		if (j + 1 < size && heapTable[j + 1] > heapTable[j])
		{
			j++;
		}
		if (value >= heapTable[j])
		{
			break;
		}
		heapTable[i] = heapTable[j];
		heapTable[j] = value;
		i = j;
		j = 2 * j + 1;
	}
}

void Heap::Add(int data)
{
	int *temp = new int[size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = heapTable[i];
	}
	delete[] heapTable;
	heapTable = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		heapTable[i] = temp[i];
	}
	heapTable[size] = data;
	size++;
	delete[] temp;
	SortHeapUp(data);
}

void Heap::DeleteRoot()
{
	if (size == 0)
	{
		cout << "Kopiec jest juz pusty." << endl;
	}
	else
	{
		int value = heapTable[size - 1];
		heapTable[0] = value;
		size--;
		int *temp = new int[size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = heapTable[i];
		}
		delete[] heapTable;
		heapTable = new int[size];
		for (int i = 0; i < size; i++)
		{
			heapTable[i] = temp[i];
		}
		delete[] temp;
		SortHeapDown(value);
	}
}

void Heap::WriteAll(string sp, string sn, int v)
{
	if (size > 0)
	{
		string s, cr, cl, cp;

		cr = cl = cp = "  ";
		cr[0] = 218; cr[1] = 196;
		cl[0] = 192; cl[1] = 196;
		cp[0] = 179;

		if (v < size)
		{
			s = sp;
			if (sn == cr) s[s.length() - 2] = ' ';
			WriteAll(s + cp, cr, 2 * v + 2);

			s = s.substr(0, sp.length() - 2);

			cout << s << sn << heapTable[v] << endl;

			s = sp;
			if (sn == cl) s[s.length() - 2] = ' ';
			WriteAll(s + cp, cl, 2 * v + 1);
		}
	}
	else
	{
		cout << "Kopiec jest pusty" << endl;
	}
}

bool Heap::Search(int value)
{
	for (int i = 0; i < size; i++)
	{
		if (heapTable[i] == value)
			return true;
	}
	return false;
}
