#include <iostream>

#include "User.h"
using namespace std;

// https://www.tutorialspoint.com/design_pattern/mediator_pattern.htm

int main(int /*argc*/, char */*argv*/[])
{
	User bruno("Bruno");
	User mike("Mike");

	bruno.sendMessage("Hi, My name is Bruno :-)");
	mike.sendMessage("Hi there, I'm Mike!");

	return 0;
}
