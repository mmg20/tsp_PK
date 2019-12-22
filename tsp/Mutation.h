#pragma once

#include "Individual.h"

class Mutation
{
	virtual Individual execute(Individual individual) = 0;
};

