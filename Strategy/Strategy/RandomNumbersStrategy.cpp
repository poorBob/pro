#include "RandomNumbersStrategy.h"

#include <random>
#include <cmath>

void RandomNumbersStrategy::execute(const std::string &/*str*/)
{
	// Seed with a real random value, if available
	std::random_device r;

	// Choose a random mean between 1 and 6
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(1, 6);
	int mean = uniform_dist(e1);
	std::cout << "Randomly-chosen mean: " << mean << '\n';

}
