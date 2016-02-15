#ifndef artist_hxx
#define artist_hxx

#include <iostream>
#include <string>
using namespace std;

class Artist {

protected:
	string artistName;		//Indicates artist name
	bool artistIsGroup;				//Indicates if the artist belongs to a group
	bool artistIsSolo;				//Indicates if the artist is a solo artist

public:

	Artist() {
	}

	Artist(string n, bool g, bool s) {
		artistName = n;
		artistIsGroup = g;
		artistIsSolo = s;
	}

	/*
	string name() {
		return t;
	}

	void name (string _name){
		artistName = _name;
	}

	bool isGroup (){
		return artistIsGroup;
	}

	void group(){
		artistIsGroup = true;
	}

	bool isSolo(){
		return artistIsSolo;
	}

	void solo(){
		artistIsSolo = true;
	}

	string getInfo() {
		return
	}
	*/

};

#endif