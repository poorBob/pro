#include <iostream>

#include "Printer.h"
using namespace std;

int main()
{
	std::string name("Strategy Pattern");
	Printer printer(name);
	printer.printNormal();
	printer.printReverse();
	printer.printWithLambda();
	printer.printRandomNumbers();
	printer.printStrategyInThread(Strategy::Normal);
	return 0;
}

