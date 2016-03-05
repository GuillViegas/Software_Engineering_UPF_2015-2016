#ifndef album_hxx
#define album_hxx

#include <string>
#include "Track.hxx"

class Album{
private:
	std::list<Track> tlist;			//A list with all the album's tracks
	std::string titleAlbum;
	bool listed;

public:
	Album(){
		titleAlbum = "-- Untitled --";
		listed = false;
	}

	Album(const std::string &albumName) {
		titleAlbum = albumName;
		listed = false;
	} 

	std::string title(){
		return titleAlbum;
	}

	void title(const std::string &_title){
		titleAlbum = _title;
	}

	bool isListed(){
		return listed;
	}

	void list(){
		listed = true;
	}

	void unlist(){
		listed = false;
	}

	std::string trackList() {
		std::string list;

		if (tlist.empty()) list ="\n";
		else {
			for (std::list<Track>::iterator it=tlist.begin(); it != tlist.end(); ++it) {
				//catalog += "Album: " + (*it).title();
				//if ( !(*it).isListed() ) catalog += " [unlisted]\n";
				//else catalog += "\n";
			}
		}
		return list;

	}

};

#endif