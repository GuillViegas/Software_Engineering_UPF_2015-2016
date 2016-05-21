#ifndef artist_hxx
#define artist_hxx

#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "Track.hxx"
#include "Album.hxx"

class trackException : public std::exception {
public:
	const char * what() const throw() {
		return "The track does not exist";
	}
};

class albumException : public std::exception {
public:
	const char * what() const throw() {
		return "The album does not exist";
	}
};

class Artist {

private:
	std::string artistName;				//Artist name
	bool artistIsGroup;					//Indicates if the artist belongs to a group or solo
	std::list<Track> tracklist; 		//List with all tracks from the artist
	std::list<Album> albumlist; 		//List with all the albums

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

		return artistName + " " + label + "\n";
		
	}

	std::string tracksAlbumList() {
		std::string tracks;
		for (std::list<Album>::iterator it = albumlist.begin(); it != albumlist.end(); ++it) {
			tracks += (*it).trackList();
		}
		return tracks;
	}
	
	std::string catalogTracks() {
		std::string catalog;
		std::string dur;

		if(tracklist.empty()) return "";
		else {

			for (std::list<Track>::iterator it=tracklist.begin(); it != tracklist.end(); ++it) {				
				
				//Method to convert integer to string. With function std::to_string() doesn't work correctly, terminal doesn't 
			    //recognize the instruction as std library
				std::stringstream ss;
				ss << (*it).duration();
				dur = ss.str();

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

	void newAlbum(const std::string &albumName) {
		Album album(albumName);
		albumlist.push_back(album);
	}

	std::string catalogAlbums() {
		std::string catalog;
		if (albumlist.empty()) return "";
		else{
			for (std::list<Album>::iterator it=albumlist.begin(); it != albumlist.end(); ++it) {
				catalog += "Album: " + (*it).title();
				if ( !(*it).isListed() ) catalog += " [unlisted]\n";
				else catalog += "\n";
			}
		}
		return catalog;
	}

	std::string catalogStyles() {
		std::string styles;
		if (tracklist.empty()) return "";
		else {
			for (std::list<Track>::iterator it=tracklist.begin(); it != tracklist.end(); ++it) {

				styles += (*it).getAssociatedStylesWithTrack();
			}
		}
		return styles;
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

		if ( !isTrack ) throw trackException();
		return (*it);
	}


	Album & findAlbum(const std::string &albumName) {

		std::list<Album>::iterator it = albumlist.begin();
		bool isAlbum = false;

		while ( it != albumlist.end() and !isAlbum ) {

			if ( (*it).title() == albumName ) {
				isAlbum = true;
			}
			else ++it;
		}
		
		if (!isAlbum) throw albumException();
		return (*it);
	}


	std::string descriptionCatalog() { 
		return description() + catalogTracks() + catalogAlbums() + catalogStyles();
	}

	void assignTrackToAlbum(const std::string &trackName, const std::string &albumName) {

		Track & track = findTrack(trackName);
		Album & album = findAlbum(albumName);
		album.addTrack(track);
	}

};

#endif
