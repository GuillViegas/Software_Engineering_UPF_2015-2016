#ifndef Albuns_hxx
#define Albuns_hxx

#include <string>
using namespace std;



class Album{
protected:
	string titleAlbum;
	bool listed;

public:
	Album (){
		titleAlbum = "-- Untitled --";
		//listed = false;
	}

	string title(){
		return titleAlbum;
	}

	void title(string _title){
		titleAlbum = _title;
	}

	bool isListed(){
		return true;
	}

};

#endif