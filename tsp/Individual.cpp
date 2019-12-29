#include <vector>
#include "Individual.h"
#include "engine.h"
#include <algorithm>

using namespace std;

Individual operator+(Individual &a, Individual &b) {
	return a;
}

Individual::Individual(int nodeCount) {    //tworzenie nowego osobnika z liczb� gen�w odpowiadaj�c� liczbie w�z��w(wielko�ci problemu)


	
	vector<int> dna;
	for (int i = 0; i < nodeCount; i++)
		dna.push_back(i);

	shuffle(dna.begin(), dna.end(), engine);   // losowe mieszanie gen�w, przy u�yciu generatora mt19937_64

	this->genome = dna;
	


}

Individual::Individual(vector<int> genome) {
	this->genome = genome;
}