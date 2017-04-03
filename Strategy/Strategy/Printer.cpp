#include "Printer.h"
#include "Context.h"
#include "PrintStrategy.h"
#include "ReversePrintStrategy.h"
#include "LambdaPrintStrategy.h"
#include "RandomNumbersStrategy.h"
#include "ThreadPrinter.h"
#include <stdexcept>


// RS: We could use enum and factory pattern to create suitable strategy!!!

Printer::Printer(const std::__cxx11::string &str)
	: m_str(str)
{

}

void Printer::printNormal()
{
	Context context(new PrintStrategy);
	context.execute(m_str);
}

void Printer::printReverse()
{
	Context context(new ReversePrintStrategy);
	context.execute(m_str);
}

void Printer::printWithLambda()
{
	Context context(new LambdaPrintStrategy);
	context.execute(m_str);
}

void Printer::printRandomNumbers()
{
	Context context(new RandomNumbersStrategy);
	context.execute(m_str);
}

void Printer::printStrategyInThread(Strategy type)
{
	IStrategy * strat = nullptr;
	switch (type)
	{
		case Strategy::Normal:
			strat = new PrintStrategy();
			break;
		case Strategy::Reverse:
			// TODO: implement me
			break;
		case Strategy::Lambda:
			// TODO: implement me
			break;
		case Strategy::RandomNumbers:
			// TODO: implement me
			break;
		case Strategy::ThreadPrinting:
			throw std::invalid_argument("Thread printing is not allowed");
			break;
		default:
			break;
	}

	if (strat)
	{
		Context context(new ThreadPrinter(strat));
		context.execute(m_str);
	}
}


