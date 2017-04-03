#include "PrintStrategy.h"
#include <iostream>

void PrintStrategy::execute(const std::string & str)
{
	std::cout << getDecoration() <<  str << std::endl;
}
