#include "TSP.h"
#include "Matrix.h"
#include "Population.h"
#include "Individual.h"
#include "Selection.h"
#include "chance.h"
#include "OxCrossover.h"
#include "TournamentSelection.h"
#include <iostream>

using namespace std;

Individual TSP::run(
	int populationCount,
	int generations,
	Selection& selection,
	Crossover& crossover,
	Mutation& mutation
)
{
	Matrix matrix = MatrixProvider::get();

	// Losujemy pierwszego osobnika jako "najlepszego", d¹¿ymy do tego, by zast¹piæ go lepszymi z nowych generacji
	Individual best = Individual(matrix.getSize());
	
	Population population(populationCount);

	for (int i = 0; i < generations; i++)
	{
		vector<Individual> newPopMembers;

		for (int j = 0; j < populationCount / 2; j++)
		{
			// wybranie pierwszego osobnika do krzy¿owania
			Individual ind1 = selection.select(population);
			// wybranie drugiego osobnika do krzy¿owania
			Individual ind2 = selection.select(population);

			// krzy¿owanie lub nie, w zale¿noœci od wspó³czynnika
			Individual child1 = crossover.cross(ind1, ind2);
			Individual child2 = crossover.cross(ind2, ind1);

			// mutowanie lub nie, w zale¿noœci od wspó³czynnika
			mutation.mutate(child1);
			mutation.mutate(child2);

			newPopMembers.push_back(child1);
			newPopMembers.push_back(child2);
		}

		population = Population(newPopMembers);

		Individual bestInPop = population.getBest();

		if (bestInPop.getFitness() < best.getFitness())
			best = bestInPop;

		if (i%100==0) {
			best.print();
			cout << ": " << best.getFitness() << endl;
		}
		
	}

	return best;
}