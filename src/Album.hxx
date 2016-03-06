#ifndef album_hxx
#define album_hxx

#include <sstream>
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

	void addTrack(Track track) {
		tlist.push_back(track);
	}

	std::string trackList() {
		std::string list;
		std::stringstream ss;
		std::stringstream ss2;
		int number = 0;
		int dur;


		if (tlist.empty()) list ="";
		else {
			for (std::list<Track>::iterator it=tlist.begin(); it != tlist.end(); ++it) {
				++number;

				ss << number;
				std::string n = ss.str();

				dur = (*it).duration();
				ss2 << dur;
				std::string d = ss2.str();

				list = n + " - " + (*it).title() + " [" + d + "s]"+ "\n";

			}
		}
		return list;
	}

};

#endif