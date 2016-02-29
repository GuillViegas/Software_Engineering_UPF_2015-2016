/* Final version for lab session 2 */
#ifndef artist_hxx
#define artist_hxx

#include <iostream>
#include <string>
#include "Track.hxx"
#include "Album.hxx"

class Artist {

private:
	std::string artistName;				//Indicates artist name
	bool artistIsGroup;					//Indicates if the artist belongs to a group
	std::list<Track> tracklist; 	
	std::list<Album> albumslist; 	

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
		Track track;
		std::string name_duration;
		std::string folder;

		if(tracklist.empty())
			return "";
		else if (tracklist.size() == 1) {
			track = tracklist.front();
			name_duration = "\t" + track.title() + " [" + std::to_string(track.duration()) + "s]\n";
			folder = "\t\t" + track.master() + "\n";
			return name_duration + folder;
		}

	}
	
	void newTrack(const std::string &trackName, const unsigned int &duration, const std::string &folder) {
		Track track(trackName, duration, folder);
		tracklist.push_back(track);
	}

	/*
	void newAlbum(const std:string &album) {}

	void findTrack(const std:string &trackName) {}

	void findAlbum(const std:string &albumName) {}

	void assignTrackToAlbum(const std:string &trackName, const std:string &albumName) {}

*/
	

};

#endif