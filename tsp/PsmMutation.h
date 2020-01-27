#pragma once
#include "Mutation.h"

class PsmMutation : public Mutation
{
	public:
		PsmMutation(double);
	private:
		void mutator(Individual&);
};
	


