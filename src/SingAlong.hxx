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
		}
		return catalogArtist;
	}

	void createArtist(const std::string& name, const bool& b) {
		Artist artist(name);
		bool ver = b;
		if (ver == true){
			artist.group();
		}
		//if (b==true) artist.group();
		artistList.push_back(artist);
	}

};

#endif
