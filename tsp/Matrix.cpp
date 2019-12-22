#include <vector>
#include "Matrix.h"

using namespace std;

Matrix::Matrix(vector<vector<int>> distances) {
	this->distanceMatrix = distances;
}

int Matrix::getDistance(int a, int b) {
	return this->distanceMatrix[a][b];
}