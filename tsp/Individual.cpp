#include <vector>
#include "Individual.h"

using namespace std;

Individual operator+(Individual &a, Individual &b) {
	return a;
}

Individual::Individual() {}

Individual::Individual(vector<int> genome) {
	this->genome = genome;
}