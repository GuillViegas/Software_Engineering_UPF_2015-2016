#ifndef singalong_hxx
#define singalong_hxx

#include <exception>
#include <string>
#include <iostream>
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
				catalogArtist += (*it).description();
		}
		return catalogArtist;
	}

	void createArtist(const std::string& name, const bool& b) {
		Artist artist(name);
		if (b==true) artist.group();
		artistList.push_back(artist);
	}

	std::string findArtist(const std::string& a) {
		std::list<Artist>::iterator it = artistList.begin();
		bool isArtist = false;

		while(!isArtist and it != artistList.end()) {
			if ( (*it).name() == a) {
				isArtist = true;
			}
			else ++it;
		}

		if ( !isArtist ) throw artistException();
		//return (*it);
	}

};

#endif
