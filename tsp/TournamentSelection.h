#pragma once
#include "Selection.h"
class TournamentSelection :
	public Selection
{
	public:
		Individual select(Population) override;
};

