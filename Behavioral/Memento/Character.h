#ifndef CHARACTER_H
#define CHARACTER_H

#include <memory>
#include <string>
#include <iostream>

class Memento;

// Originator - the object that we want to save and restore
class Character
{
public:
	Character() = default;

	void move(const std::string & dir, int step);
	int getLifePoints() const;
	void setLifePoints(int value);

	std::shared_ptr<Memento> save() const;
	void restore(std::shared_ptr<Memento> & mem);

	void report();

	friend std::ostream& operator<< (std::ostream & os, const Character & ch )
	{
		return os << "Life: " << ch.lifePoints
		          << ", Direction: " << ch.moveDirection.c_str()
		          << ", Step: " << ch.moveStep;
	}

private:
	int lifePoints = 100;
	std::string moveDirection;
	int moveStep = 0;
};

#endif // CHARACTER_H
