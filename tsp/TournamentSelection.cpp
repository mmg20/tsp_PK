#include "TournamentSelection.h"
#include "Individual.h"
#include "Population.h"
#include "engine.h"

Individual TournamentSelection::select(Population pop)
{
	int k = 3; // rozmiar turnieju
	int prev, winner;

	int randomId = winner = rng(0, (int)pop.size() - 1);
	int best = pop.getIndividuals()[randomId].getFitness();

	for (int i = 0; i < k - 1; i++)
	{
		randomId = rng(0, pop.size() - 1);
		prev = pop.getIndividuals()[randomId].getFitness();

		if (prev < best)
		{
			best = prev;
			winner = randomId;
		}
	}

	return pop.getByIndex(winner);
}