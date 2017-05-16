#include "Prim.h"

Prim::Prim(Matrix & matrix)
{
	visited = new bool[matrix.size];
	for (int i = 0; i < matrix.size; i++)
	{
		visited[i] = false;
	}
}

Prim::Prim(Table & tab)
{
	visited = new bool[tab.size];
	for (int i = 0; i < tab.size; i++)
	{
		visited[i] = false;
	}
}

Prim::~Prim()
{
	delete[] visited;
}

void Prim::Run(Matrix & matrix)
{
	vertex = 0;
	visited[vertex] = true;

	//int indexOfStartingVertex;
	int indexOfEndingVertex;
	Edge temp;

	for (int i = 0; i < matrix.size - 1; i++)
	{
		// (int indexOfStartingVertex = 0; indexOfStartingVertex < matrix.size; indexOfStartingVertex++)
		//{
			for (int indexOfEndingVertex = 0; indexOfEndingVertex < matrix.size; indexOfEndingVertex++)
			{
				if (!visited[indexOfEndingVertex])
					queue.Add(vertex, indexOfEndingVertex, matrix.table[vertex][indexOfEndingVertex]);
			}
		//}

		do
		{
			temp = queue.Front();
			queue.Pop();
		} while (visited[temp.endVertex]);

		edges.AddAtTheEnd(temp.startVertex, temp.endVertex, temp.distance);
		visited[temp.endVertex] = true;
		vertex = temp.endVertex;
	}

	edges.WriteAll();
}

void Prim::Run(Table & tab)
{
	vertex = 0;
	visited[vertex] = true;

	//int indexOfStartingVertex;
	int indexOfEndingVertex;
	Edge temp;

	for (int i = 0; i < tab.size - 1; i++)
	{
		for (ListElement *y = tab.table[vertex].head; y; y = y->next)
		{
			queue.Add(vertex, y->vertex, y->weight);
		}

		do
		{
			temp = queue.Front();
			queue.Pop();
		} while (visited[temp.endVertex]);

		edges.AddAtTheEnd(temp.startVertex, temp.endVertex, temp.distance);
		visited[temp.endVertex] = true;
		vertex = temp.endVertex;
	}

	edges.WriteAll();
}
