#ifndef singalong_hxx
#define singalong_hxx

#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Artist.hxx"
#include "Track.hxx"

class artistException : public std::exception {
public:
	const char * what() const throw() {
		return "The artist does not exist";
	}
};


class SingAlong {
private:
	std::list<Artist> artistList;


public:

	SingAlong() {

	}

	std::string catalog() {
		std::string catalogArtist;
		for (std::list<Artist>::iterator it = artistList.begin(); it != artistList.end(); ++it) {
				catalogArtist += (*it).descriptionCatalog();
		}
		return catalogArtist;
	}

	void createArtist(const std::string& name, const bool& b) {
		Artist artist(name);
		if (b==true) artist.group();
		artistList.push_back(artist);
	}

	void createNewTrack(const std::string& artistName, const std::string& trackName, const std::string& file) {
		
		char data[10];
		std::ifstream in;
		std::string path ="masters/" + file;
		Artist & artist = findArtist(artistName);

		//Read music file from masters/
		in.open(path.c_str());
		in >> data;
		in.close();

		int duration = atoi(data); //char to integer
		artist.newTrack(trackName, duration, path);

	}

	Artist & findArtist(const std::string& a) {
		std::list<Artist>::iterator it = artistList.begin();
		bool isArtist = false;

		while(!isArtist and it != artistList.end()) {
			if ( (*it).name() == a) {
				isArtist = true;
			}
			else ++it;
		}

		if ( !isArtist ) throw artistException();
		return (*it);
	}

};

#endif
