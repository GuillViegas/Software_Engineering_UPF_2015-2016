#ifndef mp3converter_hxx
#define mp3converter_hxx

#include <string>
#include <fstream>

class MP3Converter {
private:

public:
	MP3Converter() {

	}

	void convert( const std::string& path, const std::string& file ){
		std::ofstream newfile( "compressed/Prefix [128].mp3" );
	}

};

#endif

