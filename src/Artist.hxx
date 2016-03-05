#ifndef artist_hxx
#define artist_hxx

#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include "Track.hxx"
#include "Album.hxx"

class MyException : public std::exception {
public:
	const char * what() const throw() {
		return "The track does not exist";
	}
};

class Artist {

private:
	std::string artistName;				//Artist name
	bool artistIsGroup;					//Indicates if the artist belongs to a group or solo
	std::list<Track> tracklist; 		//List with all tracks from the artist
	std::list<Album> albumslist; 		//List with all the albums

public:

	Artist() {
		artistName = "-- No name --";
		artistIsGroup = false;
	}

	Artist(const std::string& n) {
		artistName = n;
		artistIsGroup = false;
	}

	
	std::string name() {
		return artistName;
	}


	void name(const std::string &_name){
		artistName = _name;
	}

	
	bool isGroup(){
		return artistIsGroup;
	}

	
	void group(){
		artistIsGroup = true;
	}	
	
	std::string description() {
		std::string label;
		
		if (isGroup() == true) label = "[group]";
		else label = "[solo]";

		return artistName + " " + label + " \n";
		
	}
	
	std::string catalogTracks() {
		std::string catalog;

		if(tracklist.empty()) return "";
		else {

			for (std::list<Track>::iterator it=tracklist.begin(); it != tracklist.end(); ++it) {				
				
				//Method to convert integer to string. With function std::to_string() doesn't work correctly
				std::stringstream ss;
				ss << (*it).duration();
				std::string dur = ss.str();

				catalog += "\t" + (*it).title() + " [" + dur + "s]\n";
				catalog += "\t\t" + (*it).master() + "\n";

			}
			return catalog;
		}

	}
	
	void newTrack(const std::string &trackName, const unsigned int &duration, const std::string &folder) {
		Track track(trackName, duration, folder);
		tracklist.push_back(track);
	}


	Track & findTrack(const std::string &trackName) {

		std::list<Track>::iterator it = tracklist.begin();
		bool isTrack = false;

		while (!isTrack and it != tracklist.end()) {

			if ( (*it).title() == trackName ) {
				isTrack = true;
			}
			else ++it;		
		}

		if ( !isTrack ) throw MyException();
		return (*it);
	}

	std::string descriptionCatalog() { 
		return description() + catalogTracks();
	}

	//"An artist [solo]\n"
	//		"\tTrack 1 [120s]\n"
	//		"\t\tmasters/File1.wav\n"
	//		"\tTrack 2 [90s]\n"
	//		"\t\tmasters/File2.wav\n"

/*
	void newAlbum(const std:string &album) {}

	void findAlbum(const std:string &albumName) {}

	void assignTrackToAlbum(const std:string &trackName, const std:string &albumName) {}

*/
	

};

#endif