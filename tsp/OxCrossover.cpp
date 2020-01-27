#include "OxCrossover.h"
#include "rng.h"
#include <vector>
#include <algorithm>
#include "Crossover.h"

using namespace std;

OxCrossover::OxCrossover(double crossoverFactor)
	: Crossover(crossoverFactor) { }

Individual OxCrossover::crossoverMethod(Individual a, Individual b)
{
	Individual child(vector<int>(a.genome.size(), -1));
	int startSwatch = rng(0, a.genome.size() / 2 - 1);
	int endSwatch = rng(a.genome.size() / 2, a.genome.size() - 1);

	copy(
		a.genome.begin() + startSwatch,
		a.genome.begin() + endSwatch,
		child.genome.begin() + startSwatch
	);

	int childIndex = 0;

	for (int i = 0; i < (int)b.genome.size() || childIndex < (int)child.genome.size() - 1; i++)
	{
		if (childIndex == startSwatch)
		{
			if (endSwatch == (int)child.genome.size())
				break;

			childIndex = endSwatch;
		}

		{
			if (!this->hasAny(child.genome, b.genome[i]))
			{
				child.genome[childIndex++] = b.genome[i];
			}
		}
	}

	return child;
}

bool OxCrossover::hasAny(vector<int> v, int val)
{
	auto match = find(v.begin(), v.end(), val);

	if (match != v.end())
	{
		return true;
	}

	return false;
};