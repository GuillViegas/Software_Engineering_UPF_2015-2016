#ifndef style_hxx
#define style_hxx

#include <string>
#include "User.hxx"


class Style {
private:
	std::string _nameStyle;
	std::list<User> subscribers;

public:
	Style() {}

	Style(const std::string& n) {
		_nameStyle = n;
	}

	~Style() {}

	void setNameStyle(const std::string s) {
		_nameStyle = s;
	}

	std::string getNameStyle() {
		return _nameStyle;
	}

	void addUsertoSubscribers(const User &user) {
		subscribers.push_back(user);
	}

	std::string subscribersList() {
		std::string slist;
		for (std::list<User>::iterator it = subscribers.begin(); it != subscribers.end(); ++it) {
			slist += (*it).getName() + "\n";
		}
		return slist;
	}

};

#endif
