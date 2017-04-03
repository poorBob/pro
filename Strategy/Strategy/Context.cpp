#include "Context.h"
#include "IStrategy.h"

Context::Context(IStrategy * strat)
	: m_strategy(strat)
{

}

void Context::execute(const std::string &str)
{
	m_strategy->execute(str);
}


