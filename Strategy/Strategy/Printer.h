#ifndef PRINTER_H
#define PRINTER_H

#include <string>

enum class Strategy
{
	Normal,
	Reverse,
	Lambda,
	RandomNumbers,		// what kind of strategy is this :P?
	ThreadPrinting
};

class Printer
{
public:
	Printer(const std::string & str);
	~Printer() = default;

	void printNormal();
	void printReverse();
	void printWithLambda();
	void printRandomNumbers();
	void printStrategyInThread(Strategy type);

private:
	std::string m_str;
};

#endif // PRINTER_H
