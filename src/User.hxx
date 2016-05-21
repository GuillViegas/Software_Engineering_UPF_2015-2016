#ifndef user_hxx
#define user_hxx


class User {
private:
	std::string _name;
	std::string _mail;

public:
	User() {
		_name = "No name";
		_mail = "No mail";
	}

	User(const std::string& n, const std::string& m) {
		_name = n;
		_mail = m;
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

};

#endif
