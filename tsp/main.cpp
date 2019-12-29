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
	//ParametersProvider::setMutationChance(.2);
	double bestResult = tsp.run(10, matrix);


	//cout << matrix.getDistance(0, 1);
	
	Individual individual(matrix.getSize());
	
	
	for (int i = 0; i < individual.genome.size(); i++)
	{
		cout << individual.genome[i]<<' '; //wyswietlanie osobnika o losowych genach
	}
	

	return 0;
}