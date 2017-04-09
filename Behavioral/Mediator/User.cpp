#include "User.h"
#include "ChatRoom.h"

User::User(const string &name)
    :name(name)
{

}

string User::getName() const
{
	return name;
}

void User::setName(const string &value)
{
	name = value;
}

void User::sendMessage(const string &message)
{
	ChatRoom::showMessage(*this, message);
}
