#include "Table.h"

Table::Table()
{
	size = 0;
	table = new List[0];
}

Table::Table(int size)
{
	size = size;
	table = new List[size];
}

Table::~Table()
{
	delete[] table;
}

void Table::AddAtTheBeginning(List data)
{
	List *temp = new List[size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = table[i];
	}
	delete[] table;
	table = new List[size + 1];
	table[0] = data;
	for (int i = 0; i < size; i++)
	{
		table[i + 1] = temp[i];
	}
	size++;
	delete[] temp;
}

void Table::AddAtTheEnd(List data)
{
	List *temp = table;
	table = new List[size + 1];
	for (int i = 0; i < size; i++)
	{
		table[i] = temp[i];
	}
	table[size] = data;
	size++;
	delete[] temp;
}

void Table::AddInRandomPlace(List data, int place)
{
	if (place == 0)
	{
		AddAtTheBeginning(data);
	}
	else if (place == size)
	{
		AddAtTheEnd(data);
	}
	else if (place < 0 || place > size)
	{
		cout << "Niepoprawne miejsce do wstawienia danej." << endl;
	}
	else
	{
		List *temp = table;
		table = new List[size + 1];
		for (int i = 0; i < place; i++)
		{
			table[i] = temp[i];
		}
		table[place] = data;
		for (int i = place; i < size; i++)
		{
			table[i + 1] = temp[i];
		}
		size++;
		delete[] temp;
	}
}

void Table::DeleteFromBeginning()
{
	if (size == 0)
	{
		cout << "Tablica jest juz pusta." << endl;
	}
	else
	{
		List *temp = new List[size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = table[i];
		}
		size--;
		delete[] table;
		table = new List[size];
		for (int i = 0; i < size; i++)
		{
			table[i] = temp[i + 1];
		}
		delete[] temp;
	}
}

void Table::DeleteFromEnd()
{
	if (size == 0)
	{
		cout << "Tablica jest juz pusta." << endl;
	}
	else
	{
		List *temp = table;
		size--;
		table = new List[size];
		for (int i = 0; i < size; i++)
		{
			table[i] = temp[i];
		}
		delete[] temp;
	}
}

void Table::DeleteFromRandomPlace(int place)
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
			List *temp = new List[size];
			for (int i = 0; i < size; i++)
			{
				temp[i] = table[i];
			}
			size--;
			delete[] table;
			table = new List[size];
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

void Table::ReadFromFile(bool directed)
{
	string fileName;
	cout << "Podaj nazwe pliku: ";
	cin >> fileName;
	fstream file(fileName, ios_base::in);
	int x, y, weight;

	if (file.good())
	{
		if (table)
		{
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < table[i].size; j++)
				{
					table[i].DeleteFromEnd();
				}
			}
			delete[] table;
		}

		file >> numberOfEdges >> size >> startVertex >> endVertex;

		table = new List [size];

		for (int i = 0; i < numberOfEdges; i++)
		{
			file >> x >> y >> weight;
			table[x].AddAtTheEnd(y, weight);
			if (!directed)
			{
				table[y].AddAtTheEnd(x, weight);
			}
		}

		file.close();
	}
}

void Table::ReadFromFile(string fileName, bool directed)
{
	fstream file(fileName, ios_base::in);
	int x, y, weight;

	if (file.good())
	{
		if (table)
		{
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < table[i].size; j++)
				{
					table[i].DeleteFromEnd();
				}
			}
			delete[] table;
		}

		file >> numberOfEdges >> size >> startVertex >> endVertex;

		table = new List[size];

		for (int i = 0; i < numberOfEdges; i++)
		{
			file >> x >> y >> weight;
			table[x].AddAtTheEnd(y, weight);
			if (!directed)
			{
				table[y].AddAtTheEnd(x, weight);
			}
		}

		file.close();
	}
}

void Table::WriteAll()
{
	for (int i = 0; i < size; i++)
	{
		table[i].WriteAll();
	}
	cout << endl;
}

/*int Table::Search(int value)
{
	for (int i = 0; i < size; i++)
	{
		if (table[i] == value)
			return i;
	} 
	return -1;
}*/

/*int Table::GetSize()
{
	return size;
}*/
