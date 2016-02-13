#ifndef track_hxx
#define track_hxx

#include <string>
using namespace std;

class Track{
protected:
	string t;

public:
	Track () {
		t = "-- Untitled --";
	}

	string title(){
		return t;
	}

	void title(string _title){
		
	}
};

#endif