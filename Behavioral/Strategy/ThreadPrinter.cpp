#include "ThreadPrinter.h"
#include <thread>

ThreadPrinter::ThreadPrinter(IStrategy * strategy)
	: IStrategy(), m_strategy(strategy)
{

}

ThreadPrinter::~ThreadPrinter()
{
	if (m_strategy)
	{
		delete m_strategy;
	}
}

void ThreadPrinter::execute(const std::string & str)
{
	std::cout << "# Thread Printer begin " << std::endl;

	std::thread th(&ThreadPrinter::print, this, std::move(str));

	std::cout << "main thread id = " << std::this_thread::get_id() << std::endl;
	std::cout << "child thread id = " << th.get_id() << std::endl;
	std::cout << "Number of threads = " <<  std::thread::hardware_concurrency() << std::endl;
	th.join();

	std::cout << "# Thread Printer end " << std::endl;
}

void ThreadPrinter::print(const std::string & str)
{
	std::cout << "Inside thread " << std::endl;
	m_strategy->execute(str);
}

