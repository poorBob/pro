#include "ChatRoom.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

void ChatRoom::showMessage(const User & user, const string &text)
{
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now - std::chrono::hours(24));

	cout << std::put_time(std::localtime(&now_c), "%F %T ") << "["
	     << user.getName() << "]: " << text << endl;
}
