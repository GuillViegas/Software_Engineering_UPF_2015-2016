#ifndef portal_hxx
#define portal_hxx

#include <string>
#include <vector>
#include "Exception.hxx"

class Portal {
private:
	std::string _name;
	std::string _message;
	std::vector<std::pair<std::string,std::string> > newNotifications;

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

	void addNewNotifications(const std::string & artist, const std::string & song) {
		newNotifications.push_back(std::make_pair(artist, song));
	}

	std::string getNewNotifications() {
		std::string rss;
		std::string title;
		std::string link;
		for (int i = 0; i < newNotifications.size(); i++) {
			title ="<title>New track: '" + newNotifications[i].second + "' by '" + newNotifications[i].first + "'</title>\n";
			link = "<link>http://www.singalong.com/infoTrack?artist='" + newNotifications[i].first + "'&title='" + newNotifications[i].second + "'</link>\n";
			rss += "<item>\n" + title + link + "</item>\n";
		}
		return rss;
	}

};

#endif
