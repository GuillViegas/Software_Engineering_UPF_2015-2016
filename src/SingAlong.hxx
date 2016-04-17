#ifndef singalong_hxx
#define singalong_hxx

#include "Artist.hxx"
#include "Track.hxx"


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
				//std::cout << (*it).catalogTracks() << std::endl;
		}
		return catalogArtist;
	}

	void createArtist(const std::string& name, const bool& b) {
		Artist artist(name);
		artistList.push_back(artist);
	}

};

#endif
