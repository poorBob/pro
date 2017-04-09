#ifndef CHATROOM_H
#define CHATROOM_H

#include <string>
#include "User.h"

using namespace std;

class ChatRoom
{
public:
	ChatRoom() = default;

	static void showMessage(const User & user,  const string & text);
};

#endif // CHATROOM_H
