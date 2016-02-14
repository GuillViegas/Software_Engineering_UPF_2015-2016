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

	//Method that return some artist attributes: name, result, label
	std::string info() {
		std:string result;
		std:string label;
		
		if (group == true) label = "[group]";
		else label = "[solo]"

		result = name + " " + label + std::endl;
		return result;
	}


	//void name(std:string name) {}

	//void newTrack(std:string trackName, std:string length,std:string folder) {}

	//void newAlbum(std:string album) {}

	//void findTrack(std:string trackName) {}

	//void findAlbum(std:string albumName) {}

	//void assignTrackToAlbum(std:string trackName, std:string albumName) {}


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