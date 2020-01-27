#include "Matrix.h"
#include "trim.h"
#include "split.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

Matrix::Matrix()
{
	this->size = 0;
}

Matrix::Matrix(string fileName) {  // konstruktor tworz¹cy macierz i uzupe³niaj¹cy j¹ danymi z pliku
	
	string file;
	ifstream load;
	load.open(fileName);
	getline(load, file, (char)load.eof());
	load.close();

	vector<vector<string>> tokens;

	vector<string> lines = split(file, '\n');   //dzielenie stringa na linie
	for (int i = 0; i < (int)lines.size(); i++)
	{
		tokens.push_back(split(trim(lines[i]), ' '));  //usuwanie spacji z pliku
	}


	int size = stoi(tokens[0][0]);
	tokens.erase(tokens.begin());

	vector<vector<int>> nodes(size,vector<int>(size));

	for (int i = 0; i < (int)tokens.size(); i++)
	{
		for (int j = 0; j < (int)tokens[i].size(); j++)
		{
			nodes[i][j] = stoi(tokens[i][j]);
			nodes[j][i] = stoi(tokens[i][j]);
		}
	}

	this->size = size;
	this->distanceMatrix = nodes;


}

int Matrix::getDistance(int a, int b) {
	return this->distanceMatrix[a][b];
}

int Matrix::getSize() {
	return this->size;
}

Matrix MatrixProvider::matrix = Matrix();

void MatrixProvider::initialize(Matrix matrix) {
	MatrixProvider::matrix = matrix;
}

Matrix MatrixProvider::get()
{
	return MatrixProvider::matrix;
}



