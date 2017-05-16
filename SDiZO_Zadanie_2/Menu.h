#ifndef MENU_H
#define MENU_H
#include "Matrix.h"
#include "Table.h"
#include "Dijkstra.h"
#include "BellmanFord.h"
#include "Kruskal.h"
#include "Prim.h"
#include "Generator.h"
#include <iostream>
#include <Windows.h>
#include <limits>
#include <string>

using namespace std;

class Menu
{
private:
	int menuInput, subMenuInput;
	int density[5] = { 25, 50, 75, 99 };
	int numberOfVerticies[5] = { 25, 50, 75, 100, 150 };

	long long int start, elapsed, frequency;
	long long int measurements1[100], measurements2[100];

	Generator generator;

	string MAIN_MENU = "~~~~~~~~~~MENU GLOWNE~~~~~~~~~~\n1. Algorytm Dijkstry\n2. Algorytm Bellmana-Forda\n3. Algorytm Kruskala\n4. Algorytm Prima\n5. Testy czasowe\n0. Zakoncz\n";
	string DIJKSTRA_MENU = "~~~~~~~~~~DIJKSTRA~~~~~~~~~~\n1. Wczytaj graf z pliku\n2. Wyswietl wczytany graf\n3. Uruchom algorytm i wyswietl wyniki\n0. Cofnij\n";
	string BELLMAN_MENU = "~~~~~~~~~~BELLMAN-FORD~~~~~~~~~~\n1. Wczytaj graf z pliku\n2. Wyswietl wczytany graf\n3. Uruchom algorytm i wyswietl wyniki\n0. Cofnij\n";
	string KRUSKAL_MENU = "~~~~~~~~~~KRUSKAL~~~~~~~~~~\n1. Wczytaj graf z pliku\n2. Wyswietl wczytany graf\n3. Uruchom algorytm i wyswietl wyniki\n0. Cofnij\n";
	string PRIM_MENU = "~~~~~~~~~~PRIM~~~~~~~~~~\n1. Wczytaj graf z pliku\n2. Wyswietl wczytany graf\n3. Uruchom algorytm i wyswietl wyniki\n0. Cofnij\n";
	string TIME_MENU = "~~~~~~~~~~TESTY CZASOWE~~~~~~~~~~\n1. Algorytm Dijkstry\n2. Algorytm Bellmana-Forda\n3. Algorytm Kruskala\n4. Algorytm Prima\n0. Cofnij\n";

public:
	Menu();

	long long int ReadQPC();

	void MenuShow();
	void DijkstraMenu();
	void BellmanMenu();
	void KruskalMenu();
	void PrimMenu();
	void TimeMenu();

	
	long long int Average(long long int table[]);
	int CheckInput();
	int GenerateRandomNumber();
};

#endif