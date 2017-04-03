#ifndef ISTRATEGY
#define ISTRATEGY

#include <string>
#include <iostream>

class IStrategy
{
public:
//	IStrategy() = default;
//	virtual ~IStrategy() = default;

	IStrategy() { std::cout << "Creating strategy" << std::endl; }
//	IStrategy(IStrategy && strat) { std::cout << "Moving strategy" << std::endl; }
	virtual ~IStrategy() { std::cout << "Removing strategy" << std::endl; }

	std::string getDecoration(){ return ">>>>>> "; }

	virtual void execute(const std::string & str) = 0;
};

#endif // ISTRATEGY

