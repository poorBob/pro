#ifndef REVERSEPRINTSTRATEGY_H
#define REVERSEPRINTSTRATEGY_H

#include "IStrategy.h"

class ReversePrintStrategy : public IStrategy
{
public:
	ReversePrintStrategy() = default;
	~ReversePrintStrategy() = default;

	void execute(const std::string & str) override;
};

#endif // REVERSEPRINTSTRATEGY_H
