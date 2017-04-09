#include <iostream>
#include "Character.h"
#include <stack>

using namespace std;

// https://www.tutorialspoint.com/design_pattern/memento_pattern.htm
// http://www.vincehuston.org/dp/memento.html

void undoLastMove(Character & paladin, stack<std::shared_ptr<Memento>> & checkPoints)
{
	if (not checkPoints.empty())
	{
		paladin.restore(checkPoints.top() );
		checkPoints.pop();
	}
	else
	{
		cout << "No checkpoints to restore character state!" << endl;
	}
}

// main behaves like CareTaker
int main(int /*argc*/, char *argv[])
{
	stack<std::shared_ptr<Memento>> checkPoints;

	Character paladin;
	paladin.move("north", 100);
	paladin.report();

	checkPoints.push(paladin.save());

	paladin.setLifePoints(87);
	paladin.move("south", 50);
	paladin.report();

	checkPoints.push(paladin.save());

	paladin.setLifePoints(32);
	paladin.move("west", 353);
	paladin.report();

	checkPoints.push(paladin.save());

	paladin.setLifePoints(0);
	paladin.move("north-west", 90);
	paladin.report();

	undoLastMove(paladin, checkPoints);
	paladin.report();

	undoLastMove(paladin, checkPoints);
	paladin.report();

	undoLastMove(paladin, checkPoints);
	paladin.report();

	undoLastMove(paladin, checkPoints);
	paladin.report();

	return 0;
}
