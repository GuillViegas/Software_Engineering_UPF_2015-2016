/* Final version for lab session 2 */
#ifndef artist_hxx
#define artist_hxx

#include <iostream>
#include <string>
#include "Track.hxx"
#include "Albuns.hxx"

class Artist {

protected:
	std::string artistName;		//Indicates artist name
	bool artistIsGroup;				//Indicates if the artist belongs to a group
	std::list<Track> tracklist; 	
	std::list<Album> albumslist; 	

public:

	Artist() {
		artistName = "-- No name --";
		artistIsGroup = false;
	}

	Artist(std::string n) {
		artistName = n;
		artistIsGroup = false;
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
	
	void newTrack(std::string trackName, unsigned int duration, std::string folder) {
		Track track(trackName, duration, folder);
		tracklist.push_back(track);
	}

	/*
	void newAlbum(std:string album) {}

	void findTrack(std:string trackName) {}

	void findAlbum(std:string albumName) {}

	void assignTrackToAlbum(std:string trackName, std:string albumName) {}

*/
	

};

#endif