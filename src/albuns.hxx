#ifndef albuns_hxx
#define albuns_hxx

#include <string>
using namespace std;


class Album{
protected:
	string titleAlbum;

public:
	Album (){
		titleAlbum = "-- Untitled --";
	}


public:
	string title(){
		return titleAlbum;
	}

/*
public:
	void title(string _title){
		//t = _title;
	}
*/
};

#endif