/* Final version for lab session 2 */
#ifndef track_hxx
#define track_hxx

#include <string>

class Track{
protected:
	std::string trackTitle;
	unsigned int trackDuration;
	std::string trackPath;

public:
	Track () {
		trackTitle = "-- Untitled --";
		trackDuration = 0u;
		trackPath = "";
	}

	std::string title(){
		return trackTitle;
	}

	void title(std::string _title){
		trackTitle = _title;
	}

	unsigned int duration(){
		return trackDuration;
	}

	void duration(unsigned int _duration){
		trackDuration = _duration;
	}

	std::string master(){
		return trackPath;
	}

	void master(std::string _trackPath){
		trackPath = _trackPath;
	}
};

#endif