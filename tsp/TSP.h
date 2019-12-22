#pragma once

#include <vector>
#include "Matrix.h"

using namespace std;

class TSP
{	
	public:
		double run(int populationCount, Matrix distanceMatrix);
};