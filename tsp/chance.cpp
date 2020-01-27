#include "chance.h"
#include "engine.h"


using namespace std;

bool chance(double percentage)
{
	bernoulli_distribution distribution(percentage);

	return distribution(engine);
}