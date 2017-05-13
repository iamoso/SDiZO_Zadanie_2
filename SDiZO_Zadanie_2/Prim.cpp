#include "Prim.h"

Prim::Prim(Matrix & matrix)
{
	visited = new bool[matrix.size];
	for (int i = 0; i < matrix.size; i++)
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
		cout << "vertex: " << vertex << endl;
		cout << "start vertex: " << temp.startVertex << endl;
		cout << "end vertex: " << temp.endVertex << endl;
		edges.AddAtTheEnd(temp.startVertex, temp.endVertex, temp.distance);
		visited[temp.endVertex] = true;
		vertex = temp.endVertex;
	}

	edges.WriteAll();
}
