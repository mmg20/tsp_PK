#pragma once

#include <vector>
#include "Matrix.h"
#include "Individual.h"
#include "Mutation.h"
#include "Crossover.h"
#include "Selection.h"

using namespace std;

class TSP
{	
	public:
		Individual run(
			int populationCount,
			int generations,
			Selection& selection,
			Crossover& crossover,
			Mutation& mutation
		);
};