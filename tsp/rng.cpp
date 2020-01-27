#include "rng.h"
#include "engine.h"


using namespace std;

int rng(int min, int max)
{
	uniform_int_distribution<int> distribution(min, max);

	return distribution(engine);
}