#include "Generator.h"

void Generator::generateGraph(int numberOfVerticies, int density)
{
	matrix = new Matrix(numberOfVerticies, 0, numberOfVerticies - 1);
	
	float edgesRatio = (float)density / 100;
	int maxNumberOfEdges = edgesRatio*((numberOfVerticies*(numberOfVerticies - 1)) / 2);
	int randomWeight;
	int randomStartVertex;
	int randomEndVertex;

	srand(time(NULL));
	for (int i = 0; i < numberOfVerticies; i++)
	{
		randomWeight = rand() % 51 + 1;
		matrix->table[i][(i + 1) % numberOfVerticies] = randomWeight;
		matrix->numberOfEdges++;
	}

	while (matrix->numberOfEdges < maxNumberOfEdges)
	{
		randomWeight = rand() % 41 + 1;
		randomStartVertex = rand() % numberOfVerticies;
		randomEndVertex = rand() % numberOfVerticies;

		while (randomStartVertex == randomEndVertex)
		{
			randomEndVertex = rand() % numberOfVerticies;
		}

		if (matrix->table[randomStartVertex][randomEndVertex] == numeric_limits<int>::max())
		{
			matrix->table[randomStartVertex][randomEndVertex] = randomWeight;
			matrix->numberOfEdges++;
		}
	}

	WriteToFile();
}

void Generator::WriteToFile()
{
	fstream file;

	file.open("graph.txt", ios::out | ios::trunc);
	if (file.is_open())
	{
		file << matrix->numberOfEdges << " " << matrix->size << " " << matrix->startVertex << " " << matrix->endVertex << endl;
		for (int i = 0; i < matrix->size; i++)
		{
			for (int j = 0; j < matrix->size; j++)
			{
				if (matrix->table[i][j] < numeric_limits<int>::max())
					file << i << " " << j << " " << matrix->table[i][j] << endl;
			}
		}
		file.close();
	}
	else
		cout << "Nie otworzono pliku" << endl;
}
