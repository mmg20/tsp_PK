#include <vector>
#include "Individual.h"
#include "Matrix.h"
#include "engine.h"
#include <algorithm>
#include <iostream>

using namespace std;

Individual::Individual(int nodeCount) {    //tworzenie nowego osobnika z liczb¹ genów odpowiadaj¹c¹ liczbie wêz³ów(wielkoœci problemu)


	
	vector<int> dna;
	for (int i = 0; i < nodeCount; i++)
		dna.push_back(i);

	shuffle(dna.begin(), dna.end(), engine);   // losowe mieszanie genów, przy u¿yciu generatora mt19937_64

	this->genome = dna;
	


}

Individual::Individual(vector<int> genome) {
	this->genome = genome;
}

void Individual::print() {

	cout << '[';
	for (int i = 0; i < (int)this->genome.size() - 1; i++)
	{
		cout << this->genome[i] << ',';
	}
	cout << this->genome[this->genome.size() - 1] << ']';
}

int Individual::getFitness()
{
	Matrix matrix = MatrixProvider::get();

	int fitness = 0;

	for (int i = 1; i < (int)genome.size(); i++)
		fitness += matrix.getDistance(genome[i - 1], genome[i]);

	fitness += matrix.getDistance(genome[0], genome[genome.size() - 1]);

	return fitness;
}