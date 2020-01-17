#include "Population.h"
#include "engine.h"
#include "Matrix.h"

Population::Population(int size)
{
	Matrix matrix = MatrixProvider::get();

	for (int i = 0; i < size; i++)
	{
		this->individuals.push_back(Individual(matrix.getSize()));
	}
}

Population::Population(vector<Individual> individuals)
{
	this->individuals = individuals;
}

Individual Population::getBest()
{
	Individual winner = individuals[0];
	for (int i = 1; i < (int)individuals.size(); i++)
	{
		if (individuals[i].getFitness() < winner.getFitness())
			winner = individuals[i];
	}

	return winner;
}

vector<Individual> Population::getIndividuals()
{
	return this->individuals;
}

int Population::size()
{
	return this->individuals.size();
}

Individual Population::getByIndex(int index)
{
	return this->individuals[index];
}