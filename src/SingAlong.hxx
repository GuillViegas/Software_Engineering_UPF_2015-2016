#ifndef singalong_hxx
#define singalong_hxx

#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <utility>
#include "Artist.hxx"
#include "Track.hxx"
#include "User.hxx"
#include "Style.hxx"
#include "Exception.hxx"


class SingAlong {

private:
	std::list<Artist> artistList;
	std::list<Style> stlist;
	std::list<User> users;
	std::vector<std::pair<std::string,std::string> > artistSuscriptionList;
	std::vector<std::pair<std::string,std::string> > portalList;

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

	// Artist & findArtist(const std::string & artistName) {
	// 	std::list<Artist>::iterator it = artistList.begin();
	// 	bool trobat = false;

	// 	while (!trobat and it != artistList.end()) {
	// 		if ((*it).name() == artistName) trobat = true;
	// 		else ++it;
	// 	}

	// 	if (!trobat) throw artistException();
	// 	return (*it);
	// }

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

	void subscribeUserToArtist(const std::string & userName, const std::string & artistName) {
		// User & user = findUser(userName);
		// Artist & artist = findArtist(artistName);
		// artist.addUsertoSubscribersArtistList(user);
		artistSuscriptionList.push_back(std::make_pair(userName,artistName));
	}

	void createNewPortal(const std::string portalName, const std::string pmessage) {
		portalList.push_back(std::make_pair(portalName, pmessage));

	}

	std::string listPortals() {
		std::string result;
		for (int i=0; i < portalList.size(); i++) {
			result += portalList[i].first + "\n" + "\t" + portalList[i].second + "\n";
		}
		return result;
	}

	std::string rssByPortal(const std::string& portal) {
		
		std::string output = "";
		bool value = portalExists(portal);

		if (!value) throw portalException();
	 	else { 
			std::string xml = "<?xml version='1.0' encoding='ISO-8859-15'?>\n";
			std::string doctype = "<!DOCTYPE rss PUBLIC '-//Netscape Communications//DTD RSS 0.91//EN'\n";
			std::string url = "'http://my.netscape.com/publish/formats/rss-0.91.dtd'>\n";
			std::string rss_version = "<rss version='0.91'>\n";
			std::string ch = "<channel>\n";
			std::string title =	"<title>SingAlong: "+ portal +"</title>\n";
			std::string link = "<link>http://www.singalong.com/" + portal + "</link>\n";
			std::string description = "<description>A portal for heavy metal fans</description>\n";
			std::string channel = "</channel>\n";
			std::string rss_label_close =	"</rss>\n";
			output = xml + doctype + url + rss_version + ch + title + link + description + channel + rss_label_close;
		}

		return output; 

	}

	bool portalExists(const std::string& portalName) {
		bool exists = false;
		int i = 0;
		while (!exists and i < portalList.size()) {
			if (portalList[i].first == portalName) exists = true;
			else i++;
		}
		return exists;
	}


};

#endif
