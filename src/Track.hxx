#ifndef track_hxx
#define track_hxx

#include <string>

class Track {
private:
	std::string trackTitle;
	unsigned int trackDuration;
	std::string trackPath;

public:
	Track () {
		trackTitle = "-- Untitled --";
		trackDuration = 0u;
		trackPath = "";
	}

	Track(const std::string &_title, const unsigned int &_duration, const std::string &folder){
		trackTitle = _title;
		trackDuration = _duration;
		trackPath = folder;
	}

	std::string title(){
		return trackTitle;
	}

	void title(const std::string &_title){
		trackTitle = _title;
	}

	unsigned int duration(){
		return trackDuration;
	}

	void duration(const unsigned int &_duration){
		trackDuration = _duration;
	}

	std::string master(){
		return trackPath;
	}

	void master(const std::string &_trackPath){
		trackPath = _trackPath;
	}
};

#endif
