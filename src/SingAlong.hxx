#ifndef singalong_hxx
#define singalong_hxx

#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Artist.hxx"
#include "Track.hxx"
// #include "ConverterGroup.hxx"

class artistException : public std::exception {
public:
	const char * what() const throw() {
		return "The artist does not exist";
	}
};

class directoryException : public std::exception {
public:
	const char * what() const throw() {
		return "The master file does not exist";
	}
};


class SingAlong {



private:
	std::list<Artist> artistList;
	std::list<std::string> stlist;

	const char* fakeCompressions[7] = {
		"compressed/An artist - A track [128].mp3",
		"compressed/An artist - A track [128].ogg",
		"compressed/An artist - A track [192].mp3",
		"compressed/An artist - A track [192].ogg",
		"compressed/An artist - A track [96].mp3",
		"compressed/An artist - A track [96].ogg",
		0
	};

	// ConverterGroup convertergroup;

public:

	SingAlong() {
		generateCompressions();
		// convertergroup.addConveter();
	}

	std::string catalog() {
		std::string catalogArtist;
		for (std::list<Artist>::iterator it = artistList.begin(); it != artistList.end(); ++it) {
				catalogArtist += (*it).descriptionCatalog();
				if (!(*it).catalogTracks().empty() and !(*it).catalogAlbums().empty()) 
					catalogArtist += (*it).tracksAlbumList();
				
		}
		return catalogArtist;
	}

	void createArtist(const std::string& name, const bool& b) {
		Artist artist(name);
		if (b==true) artist.group();
		artistList.push_back(artist);
	}

	void createNewTrack(const std::string& artistName, const std::string& trackName, const std::string& file) {
		char data[10];
		std::ifstream in;
		std::string path ="masters/" + file;
		Artist & artist = findArtist(artistName);
		
		//Check if path exists
		std::ifstream my_file(path.c_str());

		if ( my_file.good() ) {
			in.open(path.c_str());
			in >> data;
			in.close();
		} else throw directoryException();

		int duration = atoi(data);
		artist.newTrack(trackName, duration, path);
	}

	void includeTrackOnAlbum(const std::string& artistName, const std::string trackName, const std::string albumName) {
		Artist & artist = findArtist(artistName);
		artist.assignTrackToAlbum(trackName, albumName);
		
	}

	void createNewAlbum(const std::string& artistName, const std::string& albumName ) {
		Artist & artist = findArtist(artistName);
		artist.newAlbum(albumName);
	}

	void listAlbum(const std::string& artistName, const std::string& albumName) {
		Artist & artist = findArtist(artistName);
		Album & album = artist.findAlbum(albumName);
		album.list();
	}
	void unlistAlbum(const std::string& artistName, const std::string& albumName) {
		Artist & artist = findArtist(artistName);
		Album & album = artist.findAlbum(albumName);
		album.unlist();
	}

	Artist & findArtist(const std::string& a) {
		std::list<Artist>::iterator it = artistList.begin();
		bool isArtist = false;

		while(!isArtist and it != artistList.end()) {
			if ( (*it).name() == a) {
				isArtist = true;
			}
			else ++it;
		}
		if ( !isArtist ) throw artistException();
		return (*it);
	}

	void generateCompressions() {
		for (int i = 0; fakeCompressions[i]; ++i) 
			std::ofstream newfile( fakeCompressions[i] );
	}

	void createNewStyle(const std::string & style) {
		stlist.push_back(style);
	}

	std::string styleList() {
		std::string musicStyles;
	 	for ( std::list<std::string>::iterator it = stlist.begin(); it != stlist.end(); ++it) {
	 		musicStyles += (*it) + "\n";
	 	}
	 	return musicStyles;
	}


};

#endif
