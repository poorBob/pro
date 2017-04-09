#ifndef MEMENTO_H
#define MEMENTO_H

#include <memory>
#include <string>

class Memento
{
public:
	Memento(int life, const std::string & dir, int step);
	~Memento();

	std::string getMoveDirection() const;
	void setMoveDirection(const std::string &value);

	int getLifePoints() const;
	void setLifePoints(int value);

	int getMoveStep() const;
	void setMoveStep(int value);

private:
	int lifePoints = 0;
	std::string moveDirection;
	int moveStep = 0;
};

#endif // MEMENTO_H
