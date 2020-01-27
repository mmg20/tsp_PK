#pragma once

#include "Individual.h"

class Mutation
{	
	public:
		Mutation(double);
		void mutate(Individual&);
	// protected poniewa¿ chcemy mieæ dostêp do tych parametrów i metod w klasie dziedzicz¹cej w postaci "private"
	// "private" w klasie bazowej nie jest dziedziczone w klasie dziedzicz¹cej
	protected:
		double mutationFactor;
		bool shouldMutate();
		virtual void mutator(Individual&);
};

