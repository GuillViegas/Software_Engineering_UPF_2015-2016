#ifndef artist_hxx
#define artist_hxx

#include <iostream>
#include <string>

class Artist {

protected:
	std::string artistName;		//Indicates artist name
	bool artistIsGroup;				//Indicates if the artist belongs to a group
	bool artistIsSolo;				//Indicates if the artist is a solo artist

public:

	Artist() {
		artistName = "-- No name --";
		artistIsGroup = false;
		artistIsSolo = false;
	}

	Artist(std::string n) {
		artistName = n;
		artistIsGroup = false;
		artistIsSolo = false;
	}

	
	std::string name() {
		return artistName;
	}


	void name(std::string _name){
		artistName = _name;
	}

	
	bool isGroup(){
		return artistIsGroup;
	}

	
	void group(){
		artistIsGroup = false;
	}

	/*
	bool isSolo(){
		return artistIsSolo;
	}

	void isSolo(bool b){
		artistIsSolo = b;
	}


	//Method that return some artist attributes: name, result, label
	
	std::string description() {
		std:string result;
		std:string label;
		
		if (group == true) label = "[group]";
		else label = "[solo]"

		result = name + " " + label + std::endl;
		return result;
	}
	

	void newTrack(std:string trackName, std:string length,std:string folder) {}

	void newAlbum(std:string album) {}

	void findTrack(std:string trackName) {}

	void findAlbum(std:string albumName) {}

	void assignTrackToAlbum(std:string trackName, std:string albumName) {}

*/
	

};

#endif