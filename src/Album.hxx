/* Final version for lab session 2 */
#ifndef album_hxx
#define album_hxx

#include <string>
using namespace std;



class Album{
private:
	string titleAlbum;
	bool listed;

public:
	Album (){
		titleAlbum = "-- Untitled --";
		listed = false;
	}

	string title(){
		return titleAlbum;
	}

	void title(string _title){
		titleAlbum = _title;
	}

	bool isListed(){
		return listed;
	}

	void list(){
		listed = true;
	}

	void unlist(){
		listed = false;
	}

};

#endif