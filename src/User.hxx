#ifndef user_hxx
#define user_hxx


class User {
private:
	std::string _name;
	std::string _phone;
	std::string _mail;
	int _preferences;	//Attribute that define the preference of notification. 0 -> mail, 1 -> SMS message, 2 -> Whatsapp message

public:
	User() {
		_name = "No name";
		_mail = "No mail";
		_phone = "";
		_preferences = 0;
	}

	User(const std::string& n, const std::string& m) {
		_name = n;
		_mail = m;
		_phone = "";
		_preferences = 0;	//By default the preference is mail notification
	}

	~User() {}

	void setName(const std::string s) {
		_name = s;
	}

	std::string getName() {
		return _name;
	}

	void setMail(const std::string mailAddress) {
		_mail = mailAddress;
	}

	std::string getMail() {
		return _mail;
	}

	std::string getInfo() {
		return getName() + " " + getMail() + "\n"; 
	}

	void notify(const std::string& message) {
		std::cout << message << std::endl;
	}

	int getPreferences() {
		return _preferences;
	}

	void setPreferences(const int & p) {
		_preferences = p;
	}

	std::string getPhoneNumber() {
		return _phone;
	}

	void setPhoneNumber(const std::string & phoneNumber) {
		_phone = phoneNumber;
	}

};

#endif
