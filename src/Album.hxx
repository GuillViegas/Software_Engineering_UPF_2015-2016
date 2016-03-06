#ifndef album_hxx
#define album_hxx

#include <sstream>
#include <string>
#include "Track.hxx"

class Album{
private:
	std::list<Track> tlist;				//A list with all the album's tracks
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

	void addTrack(const Track &track) {
		tlist.push_back(track);
	}

	std::string trackList() {
		std::string list;
		int number = 0;
		std::string d, n;				//n represents the track order in the album (string format)
										//d represents the track's duration (string format)

		if (tlist.empty()) list ="";
		else {
			for (std::list<Track>::iterator it=tlist.begin(); it != tlist.end(); ++it) {

				++number;
				n = to_string( number );				
				d = to_string( (*it).duration() );		
				list += n + " - " + (*it).title() + " [" + d + "s]"+ "\n";
			}
		}
		return list;
	}

	std::string to_string(const int& number) {
		std::stringstream ss;
		//Remove ss content
		ss.str("");
		ss << number;
		return ss.str();
	}

};

#endif