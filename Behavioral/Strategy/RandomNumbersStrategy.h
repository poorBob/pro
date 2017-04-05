#ifndef RANDOMNUMBERSSTRATEGY_H
#define RANDOMNUMBERSSTRATEGY_H

#include "IStrategy.h"

class RandomNumbersStrategy : public IStrategy
{
public:
	explicit RandomNumbersStrategy() = default;
	~RandomNumbersStrategy() = default;

	void execute(const std::string &str) override;
};

#endif // RANDOMNUMBERSSTRATEGY_H
