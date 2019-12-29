#include <vector>
#include "Individual.h"
#include "engine.h"
#include <algorithm>

using namespace std;

Individual operator+(Individual &a, Individual &b) {
	return a;
}

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