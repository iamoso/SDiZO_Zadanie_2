#include "Menu.h"
#undef max

Menu::Menu()
{
	srand(time(NULL));
	MenuShow();
}

long long int Menu::ReadQPC()
{
		LARGE_INTEGER count;
		QueryPerformanceCounter(&count);
		return((long long int)count.QuadPart);
}

void Menu::MenuShow()
{
	do
	{
		cout << MAIN_MENU;
		menuInput = CheckInput();
		switch (menuInput)
		{
		case 1:
			DijkstraMenu();
			break;
		case 2:
			BellmanMenu();
			break;
		case 3:
			KruskalMenu();
			break;
		case 4:
			PrimMenu();
			break;
		case 5:
			TimeMenu();
			break;
		default:
			break;
		}
	} while (menuInput != 0);
}

void Menu::DijkstraMenu()
{
	Matrix *matrix = new Matrix();
	Table *table = new Table();
	Dijkstra *dijkstraMatrix = new Dijkstra(*matrix);
	Dijkstra *dijkstraTable = new Dijkstra(*table);

	do
	{
		cout << DIJKSTRA_MENU;
		subMenuInput = CheckInput();
		switch (subMenuInput)
		{
		case 1:
			matrix->ReadFromFile(true);
			dijkstraMatrix = new Dijkstra(*matrix);
			table->ReadFromFile(true);
			dijkstraTable = new Dijkstra(*table);
			break;
		case 2:
			cout << "------MACIERZ------" << endl;
			matrix->WriteMatrix();
			cout << "------TABLICA LIST------" << endl;
			table->WriteAll();
			break;
		case 3:
			cout << "------MACIERZ------" << endl;
			dijkstraMatrix->Run(*matrix);
			cout << "------TABLICA LIST------" << endl;
			dijkstraTable->Run(*table);
			break;
		default:
			break;
		}
	} while (subMenuInput != 0);
}

void Menu::BellmanMenu()
{
	Matrix *matrix = new Matrix();
	Table *table = new Table();
	BellmanFord *bellmanMatrix = new BellmanFord(*matrix);
	BellmanFord *bellmanTable = new BellmanFord(*table);

	do
	{
		cout << BELLMAN_MENU;
		subMenuInput = CheckInput();
		switch (subMenuInput)
		{
		case 1:
			matrix->ReadFromFile(true);
			bellmanMatrix = new BellmanFord(*matrix);
			table->ReadFromFile(true);
			bellmanTable = new BellmanFord(*table);
			break;
		case 2:
			cout << "------MACIERZ------" << endl;
			matrix->WriteMatrix();
			cout << "------TABLICA LIST------" << endl;
			table->WriteAll();
			break;
		case 3:
			cout << "------MACIERZ------" << endl;
			bellmanMatrix->Run(*matrix);
			cout << "------TABLICA LIST------" << endl;
			bellmanTable->Run(*table);
			break;
		default:
			break;
		}
	} while (subMenuInput != 0);
}

void Menu::KruskalMenu()
{
	Matrix *matrix = new Matrix();
	Table *table = new Table();
	Kruskal *kruskalMatrix = new Kruskal(*matrix);
	Kruskal *kruskalTable = new Kruskal(*table);

	do
	{
		cout << KRUSKAL_MENU;
		subMenuInput = CheckInput();
		switch (subMenuInput)
		{
		case 1:
			matrix->ReadFromFile(false);
			kruskalMatrix = new Kruskal(*matrix);
			table->ReadFromFile(false);
			kruskalTable = new Kruskal(*table);
			break;
		case 2:
			cout << "------MACIERZ------" << endl;
			matrix->WriteMatrix();
			cout << "------TABLICA LIST------" << endl;
			table->WriteAll();
			break;
		case 3:
			cout << "------MACIERZ------" << endl;
			kruskalMatrix->Run(*matrix);
			cout << "------TABLICA LIST------" << endl;
			kruskalTable->Run(*table);
			break;
		default:
			break;
		}
	} while (subMenuInput != 0);
}

void Menu::PrimMenu()
{
	Matrix *matrix = new Matrix();
	Table *table = new Table();
	Prim *primMatrix = new Prim(*matrix);
	Prim *primTable = new Prim(*table);

	do
	{
		cout << PRIM_MENU;
		subMenuInput = CheckInput();
		switch (subMenuInput)
		{
		case 1:
			matrix->ReadFromFile(false);
			primMatrix = new Prim(*matrix);
			table->ReadFromFile(false);
			primTable = new Prim(*table);
			break;
		case 2:
			cout << "------MACIERZ------" << endl;
			matrix->WriteMatrix();
			cout << "------TABLICA LIST------" << endl;
			table->WriteAll();
			break;
		case 3:
			cout << "------MACIERZ------" << endl;
			primMatrix->Run(*matrix);
			cout << "------TABLICA LIST------" << endl;
			primTable->Run(*table);
			break;
		default:
			break;
		}
	} while (subMenuInput != 0);
}

void Menu::TimeMenu()
{
	Matrix *matrix = new Matrix();
	Table *table = new Table();
	Dijkstra *dMatrix = new Dijkstra(*matrix);
	Dijkstra *dTable = new Dijkstra(*table);
	BellmanFord *bMatrix = new BellmanFord(*matrix);
	BellmanFord *bTable = new BellmanFord(*table);
	Kruskal *kMatrix = new Kruskal(*matrix);
	Kruskal *kTable = new Kruskal(*table);
	Prim *pMatrix = new Prim(*matrix);
	Prim *pTable = new Prim(*table);

	do
	{
		cout << TIME_MENU;
		subMenuInput = CheckInput();
		switch (subMenuInput)
		{
		case 1:		//Dijkstra
			for (int k = 0; k < 4; k++)
			{
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 100; j++)
					{
						generator.generateGraph(numberOfVerticies[i], density[k]);
						matrix->ReadFromFile("graph.txt", true);
						table->ReadFromFile("graph.txt", true);
						dMatrix = new Dijkstra(*matrix);
						dTable = new Dijkstra(*table);

						QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);

						start = ReadQPC();
						dMatrix->Run(*matrix);
						elapsed = ReadQPC() - start;
						elapsed = (1000000000.0 * elapsed) / frequency;
						measurements1[i] = elapsed;

						delete dMatrix;

						start = ReadQPC();
						dTable->Run(*table);
						elapsed = ReadQPC() - start;
						elapsed = (1000000000.0 * elapsed) / frequency;
						measurements2[i] = elapsed;

						delete dTable;
					}
					fstream file;

					file.open("dijkstraTesty.txt", ios::out | ios::app);
					if (file.is_open())
					{
						file << "Dijkstra Macierz: " << Average(measurements1) << "  Liczba wierzcho³ków: " << numberOfVerticies[i] << "   Gestosc: " << density[k] << endl;
						file << "Dijkstra Lista: " << Average(measurements2) << "  Liczba wierzcho³ków: " << numberOfVerticies[i] << "   Gestosc: " << density[k] << endl;
						file.close();
					}
					else
						cout << "Nie otworzono pliku" << endl;
				}
			}
			break;
		case 2:		//Bellman-Ford
			for (int k = 0; k < 4; k++)
			{
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 100; j++)
					{
						generator.generateGraph(numberOfVerticies[i], density[k]);
						matrix->ReadFromFile("graph.txt", true);
						table->ReadFromFile("graph.txt", true);
						bMatrix = new BellmanFord(*matrix);
						bTable = new BellmanFord(*table);

						QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);

						start = ReadQPC();
						bMatrix->Run(*matrix);
						elapsed = ReadQPC() - start;
						elapsed = (1000000000.0 * elapsed) / frequency;
						measurements1[i] = elapsed;

						delete bMatrix;

						start = ReadQPC();
						bTable->Run(*table);
						elapsed = ReadQPC() - start;
						elapsed = (1000000000.0 * elapsed) / frequency;
						measurements2[i] = elapsed;

						delete bTable;
					}
					fstream file;

					file.open("bellmanTesty.txt", ios::out | ios::app);
					if (file.is_open())
					{
						file << "Dijkstra Macierz: " << Average(measurements1) << "  Liczba wierzcho³ków: " << numberOfVerticies[i] << "   Gestosc: " << density[k] << endl;
						file << "Dijkstra Lista: " << Average(measurements2) << "  Liczba wierzcho³ków: " << numberOfVerticies[i] << "   Gestosc: " << density[k] << endl;
						file.close();
					}
					else
						cout << "Nie otworzono pliku" << endl;
				}
			}
			break;
		case 3:		//Kruskal
			for (int k = 0; k < 4; k++)
			{
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 100; j++)
					{
						generator.generateGraph(numberOfVerticies[i], density[k]);
						matrix->ReadFromFile("graph.txt", true);
						table->ReadFromFile("graph.txt", true);
						kMatrix = new Kruskal(*matrix);
						kTable = new Kruskal(*table);

						QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);

						start = ReadQPC();
						kMatrix->Run(*matrix);
						elapsed = ReadQPC() - start;
						elapsed = (1000000000.0 * elapsed) / frequency;
						measurements1[i] = elapsed;

						delete kMatrix;

						start = ReadQPC();
						kTable->Run(*table);
						elapsed = ReadQPC() - start;
						elapsed = (1000000000.0 * elapsed) / frequency;
						measurements2[i] = elapsed;

						delete kTable;
					}
					fstream file;

					file.open("kruskalTesty.txt", ios::out | ios::app);
					if (file.is_open())
					{
						file << "Dijkstra Macierz: " << Average(measurements1) << "  Liczba wierzcho³ków: " << numberOfVerticies[i] << "   Gestosc: " << density[k] << endl;
						file << "Dijkstra Lista: " << Average(measurements2) << "  Liczba wierzcho³ków: " << numberOfVerticies[i] << "   Gestosc: " << density[k] << endl;
						file.close();
					}
					else
						cout << "Nie otworzono pliku" << endl;
				}
			}
			break;
		case 4:		//Prim
			for (int k = 0; k < 4; k++)
			{
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 100; j++)
					{
						generator.generateGraph(numberOfVerticies[i], density[k]);
						matrix->ReadFromFile("graph.txt", true);
						table->ReadFromFile("graph.txt", true);
						pMatrix = new Prim(*matrix);
						pTable = new Prim(*table);

						QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);

						start = ReadQPC();
						pMatrix->Run(*matrix);
						elapsed = ReadQPC() - start;
						elapsed = (1000000.0 * elapsed) / frequency;
						measurements1[i] = elapsed;

						delete pMatrix;

						start = ReadQPC();
						pTable->Run(*table);
						elapsed = ReadQPC() - start;
						elapsed = (1000000.0 * elapsed) / frequency;
						measurements2[i] = elapsed;

						delete pTable;
					}
					fstream file;

					file.open("primTesty.txt", ios::out | ios::app);
					if (file.is_open())
					{
						file << "Dijkstra Macierz: " << Average(measurements1) << "  Liczba wierzcho³ków: " << numberOfVerticies[i] << "   Gestosc: " << density[k] << endl;
						file << "Dijkstra Lista: " << Average(measurements2) << "  Liczba wierzcho³ków: " << numberOfVerticies[i] << "   Gestosc: " << density[k] << endl;
						file.close();
					}
					else
						cout << "Nie otworzono pliku" << endl;
				}
			}
			break;
		default:
			break;
		}
	} while (subMenuInput != 0);
}

long long int Menu::Average(long long int table[])
{
	long long int average = 0;

	for  (int i = 0; i < 100; i++)
	{
		average += table[i];
	}
	return average / 100;
}

int Menu::CheckInput()
{
	int input;
	cin >> input;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cout << "Zle dane wejsciowe. Wprowadz liczbe: ";
		cin >> input;
	}
	return input;
}

int Menu::GenerateRandomNumber()
{
	int randomNumber = 100000 * ((rand() % 11000) + 10000);
	//int randomNumber = (rand() % 20000);
	return randomNumber;
}
