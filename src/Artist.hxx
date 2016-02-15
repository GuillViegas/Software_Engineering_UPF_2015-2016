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
		artistIsGroup = true;
	}

	
	bool isSolo(){
		return artistIsSolo;

	}

	
	void solo(){
		artistIsSolo = true;
	}

	
	
	std::string description() {
		std::string label;
		
		if (isGroup() == true) label = "[group]";
		else label = "[solo]";

		return artistName + " " + label + " \n";
		
	}
	
	/*
	void newTrack(std:string trackName, std:string length,std:string folder) {}

	void newAlbum(std:string album) {}

	void findTrack(std:string trackName) {}

	void findAlbum(std:string albumName) {}

	void assignTrackToAlbum(std:string trackName, std:string albumName) {}

*/
	

};

#endif