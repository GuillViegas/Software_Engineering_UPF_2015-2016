#ifndef portal_hxx
#define portal_hxx

#include <string>
#include "Exception.hxx"

class Portal {
private:
	std::string _name;
	std::string _message;
	std::string _newNotifications;

public:
	Portal() {}

	Portal(const std::string &n, const std::string &m) {
		_name = n;
		_message = m;
		_newNotifications = "";
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

	void addNewNotifications(const std::string & artist, const std::string & song) {
		std::string title ="<title>New track: '" + song + "' by '" + artist + " '</tile>\n";
		std::string link = "<link>http://www.singalong.com/infoTrack?artist='" + artist + "'&title='" + song + "'</link>\n";
		_newNotifications += "<item>\n" + title + link + "</item>\n";
	}

	std::string getNewNotifications() {
		return _newNotifications;
	}

};

#endif
