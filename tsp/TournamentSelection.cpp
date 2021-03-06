#include "TournamentSelection.h"
#include "Individual.h"
#include "rng.h"
#include "Population.h"
#include "engine.h"

Individual TournamentSelection::selector(Population pop)
{
	int k = 3; // rozmiar turnieju
	int prev, winner; // poprzedni,  wygrany

	int randomId = winner = rng(0, (int)pop.size() - 1); // przypisujemy do winnera losowy indeks z populacji
	int best = pop.getIndividuals()[randomId].getFitness(); // dlugosc cyklu hamiltona

	for (int i = 0; i < k - 1; i++) // k-1 dlatego ze jeden jest juz wylosowany
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