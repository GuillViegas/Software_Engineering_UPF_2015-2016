#ifndef album_hxx
#define album_hxx

#include <string>

class Album{
private:
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

};

#endif