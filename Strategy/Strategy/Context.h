#ifndef CONTEXT_H
#define CONTEXT_H

#include <memory>

//forward declaration
class IStrategy;

class Context
{
public:
	Context(IStrategy * strat);
	~Context() = default;

	void execute(const std::string & str);

private:
	std::unique_ptr<IStrategy> m_strategy;
};

#endif // CONTEXT_H
