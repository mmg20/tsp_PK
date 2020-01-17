#include "engine.h"

random_device rd;
mt19937_64 engine(rd());

int rng(int min, int max)
{
	uniform_int_distribution<int> distribution(min, max);

	return distribution(engine);
}