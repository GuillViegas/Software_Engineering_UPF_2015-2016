#ifndef artist_hxx
#define artist_hxx

#include <iostream>
#include <string>

class Artist {

public:

	Artist() {
	}

	Artist(std::string n, bool g, bool s) {
		name = n;
		group = g;
		solo = s;
	}

	/*
	std::string getName() {
		return t;
	}*/

	/*
	std::string getInfo() {
		return
	}
	*/

private:
	std::string name;		//Indicates artist name
	bool group;				//Indicates if the artist belongs to a group
	bool solo;				//Indicates if the artist is a solo artist

};

#endif