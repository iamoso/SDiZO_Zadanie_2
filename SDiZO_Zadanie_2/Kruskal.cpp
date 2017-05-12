#include "Kruskal.h"

Kruskal::Kruskal(Matrix &matrix)
{
	set = new int[matrix.size];
	for (int i = 0; i < matrix.size; i++)
	{
		set[i] = i;
	}
}

Kruskal::~Kruskal()
{
}

void Kruskal::Run(Matrix & matrix)
{
	Edge temp;
	int setTemp;

	for (int i = 0; i < matrix.size; i++)
	{
		for (int j = 0; j < matrix.size; j++)
		{
			if (matrix.table[i][j] < numeric_limits<int>::max())
			{
				queue.Add(i, j, matrix.table[i][j]);
			}
		}
	}

	for (int i = 0; i < matrix.size - 1; i++)
	{
		do
		{
			temp = queue.Front();
			queue.Pop();
		} while (set[temp.startVertex] == set[temp.endVertex]);
		edges.AddAtTheEnd(temp.startVertex, temp.endVertex, temp.distance);
		setTemp = set[temp.endVertex];
		set[temp.endVertex] = set[temp.startVertex];
		for (int indexOfSet = 0; indexOfSet < matrix.size; indexOfSet++)
		{
			if (set[indexOfSet] == setTemp)
				set[indexOfSet] = set[temp.startVertex];
		}
	}

	edges.WriteAll();
}
