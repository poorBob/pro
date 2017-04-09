#include "Character.h"
#include "Memento.h"

void Character::move(const std::string &dir, int step)
{
	moveDirection = dir;
	moveStep = step;
}

int Character::getLifePoints() const
{
	return lifePoints;
}

void Character::setLifePoints(int value)
{
	lifePoints = value;
}

std::shared_ptr<Memento> Character::save() const
{
	return std::make_shared<Memento>(lifePoints, moveDirection, moveStep);
}

void Character::restore(std::shared_ptr<Memento> &mem)
{
	std::cout << "### Restoring previous life and move values" << std::endl;
	lifePoints = mem->getLifePoints();
	moveDirection = mem->getMoveDirection();
	moveStep = mem->getMoveStep();
}

void Character::report()
{
	std::cout << *this << std::endl;
}
