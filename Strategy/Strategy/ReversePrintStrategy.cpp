#include "ReversePrintStrategy.h"
#include <algorithm>

void ReversePrintStrategy::execute(const std::string & str)
{
	std::string localStr(str);
	std::reverse(std::begin(localStr), std::end(localStr));
	std::cout << getDecoration() << localStr << std::endl;
}
