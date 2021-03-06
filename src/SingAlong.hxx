#ifndef singalong_hxx
#define singalong_hxx

#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <utility>
#include "Artist.hxx"
#include "externalLibs/MailStub.hxx"
#include "Portal.hxx"
#include "Track.hxx"
#include "User.hxx"
#include "Style.hxx"
#include "Exception.hxx"
#include "gui/Model.hxx"


class SingAlong: public Model {

private:
	std::list<Artist> artistList;
	std::list<Style> stlist;
	std::list<User> users;
	std::vector<std::pair<std::string,std::string> > artistSuscriptionList;
	std::vector<std::pair<std::string,std::string> > artistPortalSuscriptionList;
	std::vector<std::pair<std::string,std::string> > stylePortalSuscriptionList;
	std::list<Portal> portalList;

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
		notifyUsersSubscribedToArtist(artistName, trackName);
		updatePortalsAssociatedWithArtirst(artistName, trackName);
	}

	void updatePortalsAssociatedWithArtirst(const std::string & artistName, const std::string & trackName) {

		for (int i = 0; i < artistPortalSuscriptionList.size(); i++) {	
			if (artistPortalSuscriptionList[i].second == artistName) {
				Portal & portal = findPortal(artistPortalSuscriptionList[i].first);
				portal.addNewNotifications(artistName, trackName);
			}		
		}
	}

	void updatePortalsAssociatedWithStyle(const std::string & style, const std::string & artistName, const std::string & trackName) {

		for (int i = 0; i < stylePortalSuscriptionList.size(); i++) {	
			if (stylePortalSuscriptionList[i].second == style) {
				Portal & portal = findPortal(stylePortalSuscriptionList[i].first);
				portal.addNewNotifications(artistName, trackName);
			}		
		}
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
		updatePortalsAssociatedWithStyle(style, artistName, trackName);
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

	User & findUser(const std::string & userName) {
		std::list<User>::iterator it = users.begin();
		bool trobat = false;

		while (!trobat and it != users.end()) {

			std::string str1 = (*it).getName();
			//if ( (*it).getName() == userName ) trobat = true;
			if ( str1.compare(userName) == 0 ) trobat = true;
			else ++it;
		}

		if (!trobat) throw userException();
		return (*it);
	}

	Portal & findPortal(const std::string& portalName) {
		bool exists = false;
		std::list<Portal>::iterator it = portalList.begin();

		while (!exists and it != portalList.end()) {
			if ((*it).getPortalName() == portalName) exists = true;
			else ++it;
		}

		if (!exists) throw portalException();
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

	void subscribeUserToArtist(const std::string & userName, const std::string & artistName) {
		artistSuscriptionList.push_back(std::make_pair(userName,artistName));
	}

	void subscribePortalToArtist(const std::string & portalName, const std::string & artistName) {
		artistPortalSuscriptionList.push_back(std::make_pair(portalName,artistName));
	}

	void subscribePortalToStyle(const std::string & portal, const std::string & style) {
		stylePortalSuscriptionList.push_back(std::make_pair(portal, style));
	}

	void createNewPortal(const std::string portalName, const std::string pmessage) {
		Portal portal(portalName,pmessage);
		portalList.push_back(portal);

	}

	std::string listPortals() {
		std::string result;
		for (std::list<Portal>::iterator it = portalList.begin(); it != portalList.end(); it++) {
			result += (*it).getPortalName() + "\n" + "\t" + (*it).getMessage() + "\n";
		}
		return result;
	}

	std::string rssByPortal(const std::string& portalName) {
		
		std::string output;

		Portal & portal = findPortal(portalName);
		
		std::string xml = "<?xml version='1.0' encoding='ISO-8859-15'?>\n";
		std::string doctype = "<!DOCTYPE rss PUBLIC '-//Netscape Communications//DTD RSS 0.91//EN'\n";
		std::string url = "'http://my.netscape.com/publish/formats/rss-0.91.dtd'>\n";
		std::string rss_version = "<rss version='0.91'>\n";
		std::string ch = "<channel>\n";
		std::string title =	"<title>SingAlong: "+ portalName +"</title>\n";
		std::string link = "<link>http://www.singalong.com/" + portalName + "</link>\n";
		std::string description = "<description>A portal for heavy metal fans</description>\n";
		std::string notifications = portal.getNewNotifications();
		std::string channel = "</channel>\n";
		std::string rss_label_close =	"</rss>\n";
		return output = xml + doctype + url + rss_version + ch + title + link + description + notifications + channel + rss_label_close;
	}



	void notifyUsersSubscribedToArtist(const std::string & artistName, const std::string & song) {	
		
		for (int i = 0; i < artistSuscriptionList.size(); i++) {
			
			if (artistSuscriptionList[i].second == artistName) {

				User & user = findUser(artistSuscriptionList[i].first);

				if (user.getPreferences() == "mail") {
					std::string to = user.getName() + " <" + user.getMail() + ">";
					std::string subject = "new track " + song +" by " + artistName;
					MailStub::theInstance().sendMail(to, subject);
				} else if (user.getPreferences() == "sms") {
					std::string text = "[SingAlong] new track " + song + " by " + artistName + "\n" ;
					SmsStub::theInstance().sendSms(user.getPhoneNumber(), text);
				} else {
					std::string text = "[SingAlong] new track " + song + " by " + artistName + "\n" ;;
					WhatsappStub::theInstance().sendWhatsapp(user.getPhoneNumber(), text);
				}
				
			}
		}
	}
	

	void userPrefersSms(const std::string & userName, const std::string & phoneNumber) {
		User & user = findUser(userName);
		user.setPhoneNumber(phoneNumber);
		user.setPreferences("sms");
	}

	void userPrefersWhatsapp(const std::string & userName, const std::string & phoneNumber) {
		User & user = findUser(userName);
		user.setPhoneNumber(phoneNumber);
		user.setPreferences("whatsapp");
	}

};

#endif
