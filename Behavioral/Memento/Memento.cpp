#include "Memento.h"
#include <iostream>

Memento::Memento(int life, const std::string &dir, int step)
    : lifePoints(life), moveDirection(dir), moveStep(step)
{
	std::cout << "Creating Memento! Life: " << lifePoints << ", direction: "
	          << moveDirection << ", step: " << step << std::endl;
}

Memento::~Memento()
{
	std::cout << "Destroing Memento!" << std::endl;
}

std::string Memento::getMoveDirection() const
{
	return moveDirection;
}

void Memento::setMoveDirection(const std::string &value)
{
	moveDirection = value;
}

int Memento::getLifePoints() const
{
	return lifePoints;
}

void Memento::setLifePoints(int value)
{
	lifePoints = value;
}

int Memento::getMoveStep() const
{
	return moveStep;
}

void Memento::setMoveStep(int value)
{
	moveStep = value;
}


