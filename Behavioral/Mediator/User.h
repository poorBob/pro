#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User
{
public:
	User(const string & name);

	string getName() const;
	void setName(const string &value);

	void sendMessage(const string & message);

private:
	string name;
};

#endif // USER_H
