#include "Dijkstra.h"

Dijkstra::Dijkstra(Matrix &matrix)
{
	dist = new int[matrix.size];
	prev = new int[matrix.size];
	collectionQS = new bool[matrix.size];

	for (int i = 0; i < matrix.size; i++)
	{
		dist[i] = numeric_limits<int>::max();
		prev[i] = -1;
		collectionQS[i] = false;
	}
	dist[matrix.startVertex] = 0;
	numberOfNeighbours = 0;
}

Dijkstra::Dijkstra(Table & tab)
{
	dist = new int[tab.size];
	prev = new int[tab.size];
	collectionQS = new bool[tab.size];

	for (int i = 0; i < tab.size; i++)
	{
		dist[i] = numeric_limits<int>::max();
		prev[i] = -1;
		collectionQS[i] = false;
	}
	dist[tab.startVertex] = 0;
	numberOfNeighbours = 0;
}

Dijkstra::~Dijkstra()
{
	delete[] dist;
	delete[] prev;
	delete[] collectionQS;
}

void Dijkstra::Run(Matrix &matrix)
{
	int indexOfVertex;		// indeks wierzcho³ka
	int lowestDistVertex;	// indeks wierzcho³ka o najmniejszym koszcie dojœcia

	for (int i = 0; i < matrix.size; i++)
	{
		// pêtla ustawiaj¹ca indeks wierzcho³ka na pierwszym nie zbadanym jeszcze wierzcho³ku
		for (indexOfVertex = 0; collectionQS[indexOfVertex]; indexOfVertex++);
		for (lowestDistVertex = indexOfVertex++; indexOfVertex < matrix.size; indexOfVertex++)
		{
			if (dist[indexOfVertex] < dist[lowestDistVertex] && !collectionQS[indexOfVertex])
				lowestDistVertex = indexOfVertex;
		}

		// ustawienie wierzcho³ka o najmniejszym koszcie dojœcia jako sprawdzony
		collectionQS[lowestDistVertex] = true;

		neighbours = new int;

		for (indexOfVertex = 0; indexOfVertex < matrix.size; indexOfVertex++)
		{
			if (matrix.table[lowestDistVertex][indexOfVertex] < numeric_limits<int>::max())
			{
				AddToTable(indexOfVertex, numberOfNeighbours);
				numberOfNeighbours++;
			}
		}
		
		for (indexOfVertex = 0; indexOfVertex < numberOfNeighbours; indexOfVertex++)
		{
			if (collectionQS[neighbours[indexOfVertex]]);
			else if (dist[neighbours[indexOfVertex]] > dist[lowestDistVertex] + matrix.table[lowestDistVertex][neighbours[indexOfVertex]])
			{
				dist[neighbours[indexOfVertex]] = dist[lowestDistVertex] + matrix.table[lowestDistVertex][neighbours[indexOfVertex]];
				prev[neighbours[indexOfVertex]] = lowestDistVertex;
			}
		}

		numberOfNeighbours = 0;
		delete[] neighbours;
	}

	for (int i = 0; i < matrix.size; i++)
	{
		cout << i << ": " << dist[i] << " " << prev[i] << endl;
	}
}

void Dijkstra::Run(Table &tab)
{
	int indexOfVertex;		
	int lowestDistVertex;


	for (int i = 0; i < tab.size; i++)
	{
		// pêtla ustawiaj¹ca indeks wierzcho³ka na pierwszym nie zbadanym jeszcze wierzcho³ku
		for (indexOfVertex = 0; collectionQS[indexOfVertex]; indexOfVertex++);
		for (lowestDistVertex = indexOfVertex++; indexOfVertex < tab.size; indexOfVertex++)
		{
			if (dist[indexOfVertex] < dist[lowestDistVertex] && !collectionQS[indexOfVertex])
				lowestDistVertex = indexOfVertex;
		}

		// ustawienie wierzcho³ka o najmniejszym koszcie dojœcia jako sprawdzony
		collectionQS[lowestDistVertex] = true;

		for (ListElement *y = tab.table[lowestDistVertex].head; y; y = y->next)
		{
			if (!collectionQS[y->vertex] && dist[y->vertex] > dist[lowestDistVertex] + y->weight)
			{
				dist[y->vertex] = dist[lowestDistVertex] + y->weight;
				prev[y->vertex] = lowestDistVertex;
			}
		}
	}

	for (int i = 0; i < tab.size; i++)
	{
		cout << i << ": " << dist[i] << " " << prev[i] << endl;
	}
}

void Dijkstra::write(Table & tab)
{
	int j = 0;
	cout << "^^^^^^^^^^^^^" << endl;
	for (List *i = tab.table; i < tab.table + tab.size; i++)
	{
		cout << j << ": ";
		i->WriteAll();
		j++;
	}
}

void Dijkstra::AddToTable(int data, int currentSize)
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
