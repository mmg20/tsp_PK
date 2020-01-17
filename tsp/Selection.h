#pragma once

#include "Individual.h"
#include "Population.h"

class Selection
{
	public:
		virtual Individual select(Population);
};