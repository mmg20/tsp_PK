#include "main.h"
#include "TSP.h"
#include "Matrix.h"

int main(int argc, char **argv) {
	TSP tsp;
	Matrix matrix(vector<vector<int>>(10));
	ParametersProvider::setMutationChance(.2);
	double bestResult = tsp.run(10, matrix);
		
	return 0;
}