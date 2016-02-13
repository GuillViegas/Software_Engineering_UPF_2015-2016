#ifndef albuns_hxx
#define albuns_hxx

#include <string>
using namespace std;


class Album{
protected:
	string t;

public:
	Album (){
		t = "-- Untitled --";
	}


public:
	string title(){
		//return "";
		return t;
	}

/*
public:
	void title(string _title){
		//t = _title;
	}
*/
};

#endif