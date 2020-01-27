#include "Selection.h"
#include "Individual.h"
#include "Population.h"

Selection::Selection() { }

Individual Selection::select(Population population)
{
	return this->selector(population);
}

Individual Selection::selector(Population)
{
	throw "Please implement Selection::selector in derived class";
}