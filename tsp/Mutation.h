#pragma once

#include "Individual.h"

class Mutation
{	
	public:
		Mutation(double);
		void mutate(Individual&);
	// protected poniewa� chcemy mie� dost�p do tych parametr�w i metod w klasie dziedzicz�cej w postaci "private"
	// "private" w klasie bazowej nie jest dziedziczone w klasie dziedzicz�cej
	protected:
		double mutationFactor;
		bool shouldMutate();
		virtual void mutator(Individual&);
};

