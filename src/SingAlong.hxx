#ifndef singalong_hxx
#define singalong_hxx

#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Artist.hxx"
#include "Track.hxx"
#include "User.hxx"
#include "Style.hxx"
#include "Exception.hxx"


// class artistException : public std::exception {
// public:
// 	const char * what() const throw() {
// 		return "The artist does not exist";
// 	}
// };

// class directoryException : public std::exception {
// public:
// 	const char * what() const throw() {
// 		return "The master file does not exist";
// 	}
// };

// class styleException : public std::exception {
// public:
// 	const char * what() const throw() {
// 		return "The style does not exist";
// 	}
// };

// class userException : public std::exception {
// public:
// 	const char * what() const throw() {
// 		return "The user does not exist";
// 	}
// };


class SingAlong {

private:
	std::list<Artist> artistList;
	std::list<Style> stlist;
	std::list<User> users;

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

	void createNewStyle(const std::string & sName) {
		Style style(sName);
		stlist.push_back(style);
	}

	std::string styleList() {
		std::string musicStyles;
	 	for ( std::list<Style>::iterator it = stlist.begin(); it != stlist.end(); ++it) {
	 		musicStyles += (*it).getNameStyle() + "\n";
	 	}
	 	return musicStyles;
	}

	void associateStyleWithTrack(const std::string& style, const std::string& artistName, const std::string& trackName) {
		bool trobat = false;

		Artist & artist = findArtist(artistName);
		Track & track = artist.findTrack(trackName);

		for (std::list<Style>::iterator it = stlist.begin(); it != stlist.end(); it++) {
			if ((*it).getNameStyle() == style) {
			 	(*it).notifyUsers("new track " + track.title() + " by " + artist.name());
			 	track.addStyle(*it);
			 	trobat = true;
			}
		}

		if (!trobat) throw styleException();

	}

	void createNewUser(const std::string & name, const std::string mail) {
		User user(name, mail);
		users.push_back(user);
	}

	std::string userList() {
		std::string ulist;	//result: list of users

		for (std::list<User>::iterator it = users.begin(); it != users.end(); it++) {
			ulist += (*it).getName() + " <" + (*it).getMail() + ">" + "\n";
		}

		return ulist;

	}

	void subscribeUserToStyle(const std::string & userName, const std::string & styleName) {
		User & user = findUser(userName);
		Style & style = findStyle(styleName);
		style.addUsertoSubscribers(user);
	}

	std::string listSubscribedToStyle(const std::string & styleName) {
		Style & style = findStyle(styleName);
		return style.subscribersList();
	}

	User & findUser(const std::string &userName) {
		std::list<User>::iterator it = users.begin();
		bool trobat = false;

		while (!trobat and it != users.end()) {
			if ((*it).getName() == userName) trobat = true;
			else ++it;
		}

		if (!trobat) throw userException();
		return (*it);
	}

	Style & findStyle(const std::string &styleName) {
		std::list<Style>::iterator it = stlist.begin();
		bool trobat = false;

		while (!trobat and it != stlist.end()) {
			if ((*it).getNameStyle() == styleName) trobat = true;
			else ++it;
		}

		if (!trobat) throw styleException();
		return (*it);
	}


};

#endif
