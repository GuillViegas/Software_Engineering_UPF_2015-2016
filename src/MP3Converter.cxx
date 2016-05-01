#ifndef mp3converter_hxx
#define mp3converter_hxx

#include <fstream>
#include <iostream>
#include <string>

class MP3Converter {
private:

public:
	MP3Converter() {

	}

	void convert( const std::string& path, const std::string& file ){
		std::string outputFile( file );
		outputFile += " [128].mp3";
		std::ofstream newfile( outputFile.c_str() );
	}

	void addTextToFile( const std::string& file,  const std::string& text ) {
		std::string pathFile ("/masters");
		pathFile += file;
		std::ofstream myfile;
  		myfile.open( pathFile.c_str() );
  		myfile << text;
  		myfile.close();
	}

};

#endif

