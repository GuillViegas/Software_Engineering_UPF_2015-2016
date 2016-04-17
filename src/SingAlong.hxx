#ifndef singalong_hxx
#define singalong_hxx

#include "Artist.hxx"
#include "Track.hxx"


class SingAlong {
private:
	Artist artist;
	Album album;
	Track track;

public:

	SingAlong() {

	}

	std::string catalog() {
		return artist.catalogTracks();
	}

};

#endif
