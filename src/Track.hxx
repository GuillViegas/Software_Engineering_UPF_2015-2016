#ifndef track_hxx
#define track_hxx

#include <string>
using namespace std;

class Track{
protected:
	string trackTitle;
	unsigned int d;

public:
	Track () {
		trackTitle = "-- Untitled --";
		d = 0u;
	}

	string title(){
		return trackTitle;
	}

	void title(string _title){
		trackTitle = _title;
	}

	unsigned int duration(){
		return d;
	}
};

#endif