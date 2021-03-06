#include "main.h"
#include "Commander.h"
#include "TSP.h"
#include "trim.h"
#include "split.h"
#include "Matrix.h"
#include "Individual.h"
#include "OxCrossover.h"
#include "PsmMutation.h"
#include "TournamentSelection.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {
	Commander cmd = Commander(argc, argv);

	string fileNameParameter = cmd.getParameter("-f", "Prosze podac plik wejsciowy np. -f berlin52.txt");
	string crossoverFactorParameter = cmd.getParameter("-c", "Prosze wpisac procentowa szanse na krzyzowanie np. -c 80");
	string mutationFactorParameter = cmd.getParameter("-m", "Prosze wpisac procentowa szanse na mutacje np. -m 5");
	string populationSizeParameter = cmd.getParameter("-p", "Prosze wpisac wielkosc populacji np. -p 40");
	string generationCountParameter = cmd.getParameter("-g", "Prosze podac maksymalna liczbe generacji np. -g 10000");

	if (
		fileNameParameter.empty()
		&& crossoverFactorParameter.empty()
		&& mutationFactorParameter.empty()
		&& populationSizeParameter.empty()
		&& generationCountParameter.empty()
	)
	{
		cout << endl << "Nie mozna uruchomic programu, wymagane parametry nie sa zdefiniowane" << endl;
		return 1;
	}

	string fileName = fileNameParameter;
	float crossoverFactor = stof(crossoverFactorParameter) / 100;
	float mutationFactor = stof(mutationFactorParameter) / 100;
	int populationSize = stoi(populationSizeParameter);
	int generationCount = stoi(generationCountParameter);

	cout << "Nazwa pliku: " << fileName << endl;
	cout << "Wspolczynnik krzyzowania: " << crossoverFactor << endl;
	cout << "Wspolczynnik mutacji: " << mutationFactor << endl;
	cout << "Rozmiar populacji: " << populationSize << endl;
	cout << "Liczba generacji: " << generationCount << endl;
	cout << endl;

	TSP tsp;
	Matrix matrix(fileName);

	MatrixProvider::initialize(matrix); //odwolanie statyczne

	TournamentSelection selection;
	OxCrossover crossover(crossoverFactor);
	PsmMutation mutation(mutationFactor);

	Individual best = tsp.run(
		populationSize,
		generationCount,
		selection,
		crossover,
		mutation
	);

	cout << endl << "Najlepszy wynik wygenerowany przez algorytm: " << endl;
	best.print();
	cout << ": " << best.getFitness() << endl;

	return 0;
}