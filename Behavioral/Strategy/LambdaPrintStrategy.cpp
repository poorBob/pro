#include "LambdaPrintStrategy.h"

void LambdaPrintStrategy::execute(const std::__cxx11::string & str)
{
	auto decoration = getDecoration();
	auto func = [&decoration](const std::string & s){ std::cout << decoration << " Lambda: " << s << std::endl; };

	func(str);
}
