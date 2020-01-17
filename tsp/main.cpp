#include "main.h"
#include "TSP.h"
#include "trim.h"
#include "split.h"
#include "Matrix.h"
#include "Individual.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

int main(/*int argc, char* argv[]*/) {
	TSP tsp;
	Matrix matrix("berlin52.txt");

	MatrixProvider::initialize(matrix);

	int generations = 100;
	//ParametersProvider::setMutationChance(.2);
	double bestResult = tsp.run(10, 100);

	return 0;
}