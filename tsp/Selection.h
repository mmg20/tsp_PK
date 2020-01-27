#pragma once

#include "Individual.h"
#include "Population.h"

class Selection
{
	public:
		Selection();
		Individual select(Population);
	protected:
		virtual Individual selector(Population);
};