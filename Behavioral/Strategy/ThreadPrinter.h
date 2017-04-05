#ifndef THREADPRINTER_H
#define THREADPRINTER_H

#include "IStrategy.h"

class ThreadPrinter : public IStrategy
{
public:
	ThreadPrinter(IStrategy * strategy);
	~ThreadPrinter();

	void execute(const std::string & str) final;

private:
	void print(const std::string & str);

	IStrategy* m_strategy = nullptr;
};

#endif // THREADPRINTER_H
