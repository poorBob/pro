#ifndef LAMBDAPRINTSTRATEGY_H
#define LAMBDAPRINTSTRATEGY_H

#include "IStrategy.h"

class LambdaPrintStrategy : public IStrategy
{
public:
	explicit LambdaPrintStrategy() = default;
	~LambdaPrintStrategy() = default;

	void execute(const std::string &str) override;
};

#endif // LAMBDAPRINTSTRATEGY_H
