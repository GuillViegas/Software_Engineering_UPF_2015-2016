#ifndef track_hxx
#define track_hxx

#include <string>
using namespace std;

class Track{
protected:
	string trackTitle;

public:
	Track () {
		trackTitle = "-- Untitled --";
	}

	string title(){
		return trackTitle;
	}

	void title(string _title){
		trackTitle = _title;
	}
};

#endif