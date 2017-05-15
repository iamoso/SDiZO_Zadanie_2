#include "BellmanFord.h"

BellmanFord::BellmanFord(Matrix & matrix)
{
	dist = new int[matrix.size];
	prev = new int[matrix.size];

	for (int i = 0; i < matrix.size; i++)
	{
		dist[i] = numeric_limits<int>::max();
		prev[i] = -1;
	}
	dist[matrix.startVertex] = 0;
	numberOfNeighbours = 0;
}

BellmanFord::~BellmanFord()
{
	delete[] dist;
	delete[] prev;
	delete[] neighbours;
}

bool BellmanFord::Run(Matrix & matrix)
{
	int indexOfVertex;
	int indexOfNeighbour;

	for (int i = 1; i < matrix.size; i++)
	{
		test = true;
		
		for (indexOfVertex = 0; indexOfVertex < matrix.size; indexOfVertex++)
		{
			neighbours = new int;

			for (indexOfNeighbour = 0; indexOfNeighbour < matrix.size; indexOfNeighbour++)
			{
				if (matrix.table[indexOfVertex][indexOfNeighbour] < numeric_limits<int>::max())
				{
					AddToTable(indexOfNeighbour, numberOfNeighbours);
					numberOfNeighbours++;
				}
			}

			for (indexOfNeighbour = 0; indexOfNeighbour < numberOfNeighbours; indexOfNeighbour++)
			{
				if (dist[neighbours[indexOfNeighbour]] > abs(dist[indexOfVertex] + matrix.table[indexOfVertex][neighbours[indexOfNeighbour]]))
				{
					test = false;
					dist[neighbours[indexOfNeighbour]] = dist[indexOfVertex] + matrix.table[indexOfVertex][neighbours[indexOfNeighbour]];
					prev[neighbours[indexOfNeighbour]] = indexOfVertex;
				}
			}

			numberOfNeighbours = 0;
			delete[] neighbours;
		}

		if (test)
		{
			for (int j = 0; j < matrix.size; j++)
			{
				cout << j << ": " << dist[j] << " " << prev[j] << endl;
			}
			return true;
		}
	}
	return false;
	for (indexOfVertex = 0; indexOfVertex < matrix.size; indexOfVertex++)
	{
		neighbours = new int;

		for (indexOfNeighbour = 0; indexOfNeighbour < matrix.size; indexOfNeighbour++)
		{
			if (matrix.table[indexOfVertex][indexOfNeighbour] < numeric_limits<int>::max())
			{
				AddToTable(indexOfNeighbour, numberOfNeighbours);
				numberOfNeighbours++;
			}
		}

		for (indexOfNeighbour = 0; indexOfNeighbour < numberOfNeighbours; indexOfNeighbour++)
		{
			if (dist[neighbours[indexOfNeighbour]] > dist[indexOfVertex] + matrix.table[indexOfVertex][neighbours[indexOfNeighbour]])
			{
				for (int j = 0; j < matrix.size; j++)
				{
					cout << j << ": " << dist[j] << " " << prev[j] << endl;
				}
				return false;
			}
		}

		numberOfNeighbours = 0;
		delete[] neighbours;
	}

	for (int j = 0; j < matrix.size; j++)
	{
		cout << j << ": " << dist[j] << " " << prev[j] << endl;
	}
	return true;
}

void BellmanFord::AddToTable(int data, int currentSize)
{
	int *temp = neighbours;
	neighbours = new int[currentSize + 1];
	for (int i = 0; i < currentSize; i++)
	{
		neighbours[i] = temp[i];
	}
	neighbours[currentSize] = data;
	currentSize++;
	delete[] temp;
}
