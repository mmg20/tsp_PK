#pragma once
#include "Selection.h"

class TournamentSelection :
	public Selection
{
	private:
		Individual selector(Population);
};

