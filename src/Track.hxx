#ifndef track_hxx
#define track_hxx

#include <string>
using namespace std;

class Track{
protected:
	string trackTitle;
	unsigned int trackDuration;

public:
	Track () {
		trackTitle = "-- Untitled --";
		trackDuration = 0u;
	}

	string title(){
		return trackTitle;
	}

	void title(string _title){
		trackTitle = _title;
	}

	unsigned int duration(){
		return trackDuration;
	}

	void duration(unsigned int _duration){

	}
};

#endif