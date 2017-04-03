#ifndef PRINTSTRATEGY_H
#define PRINTSTRATEGY_H

#include "IStrategy.h"

class PrintStrategy : public IStrategy
{
public:
	PrintStrategy() = default;
	~PrintStrategy() = default;

	void execute(const std::string & str) override;

};

#endif // PRINTSTRATEGY_H
