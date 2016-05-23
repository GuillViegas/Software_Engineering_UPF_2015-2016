#ifndef portal_hxx
#define portal_hxx

#include <string>
#include "Exception.hxx"

class Portal {
private:
	std::string _name;
	std::string _message;

public:
	Portal() {}

	Portal(const std::string &n, const std::string &m) {
		_name = n;
		_message = m;
	}

	~Portal() {}

	std::string getPortalName() {
		return _name;
	}

	void setportal(const std::string n) {
		_name = n;
	}

	std::string getMessage() {
		return _message;
	}

	void setMessage(const std::string m) {
		_message = m;
	}

	std::string getInfoFromPortal() {
		return _name + "\n" + _message + "\n";
	}


};

#endif
