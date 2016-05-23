#ifndef portal_hxx
#define portal_hxx

#include <string>
#include "Exception.hxx"

class Portal {
private:
	std::string _name;
	std::string _message;

public:
	Portal();
	Portal(const std::string &name, const std::string &message) {

	}

	~Portal();

	std::string get portalName() {
		return _name;
	}

	void set portalName(const std::string n) {
		_name = n;
	}

	std::string get messageName() {
		return _message;
	}

	void set messageName(const std::string m) {
		_message = m;
	}


};

#endif
