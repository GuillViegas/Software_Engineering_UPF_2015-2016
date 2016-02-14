#ifndef Albuns_hxx
#define Albuns_hxx

#include <string>
using namespace std;



class Album{
protected:
	string titleAlbum;

public:
	Album (){
		titleAlbum = "-- Untitled --";
	}

	string title(){
		return titleAlbum;
	}

	void title(string _title){
		titleAlbum = _title;
	}

};

#endif