#include "TSP.h"
#include "Matrix.h"
#include "Population.h"
#include "Individual.h"
#include "Selection.h"
#include "TournamentSelection.h"
#include <iostream>

using namespace std;

double TSP::run(int populationCount, int generations) {
	/* CONFIGURATION */
	TournamentSelection selection = TournamentSelection();
	// PMXCrossover crossover = PMXCrossover();
	// PSMMutation mutation = PSMMutation();

	Population startingPop(populationCount);

	Population workingPop(populationCount);
	workingPop = startingPop;

	for (int i = 0; i < generations; i++)
	{
		vector<Individual> newPopMembers;

		for (int j = 0; j < populationCount / 2; j++)
		{
			// wybranie pierwszego osobnika do krzy¿owania
			Individual ind1 = selection.select(workingPop);
			ind1.print();
			cout << ": " << ind1.getFitness() << endl;

			// wybranie drugiego osobnika do krzy¿owania
			Individual ind2 = selection.select(workingPop);
			ind2.print();
			cout << ": " << ind2.getFitness() << endl;

		
		}

		//workingPop = Population(newPopMembers);
	}

	return 1;
}