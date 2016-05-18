#ifndef mp3converter_hxx
#define mp3converter_hxx

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <vector>
#include "Converter.hxx"

class MP3Converter : public Converter {
private:

public:
	MP3Converter() {}

	~MP3Converter() {}

	void convert( const std::string& path, const std::string& file ) {

		//Check if path exists
		std::ifstream my_file(path.c_str());

		if ( my_file.good() ) {
			std::string outputFile( file );
			outputFile += " [128].mp3";
			std::ofstream newfile( outputFile.c_str() );
		} else throw directoryException();
	}

	void addContentToFile( const std::string& file,  const std::string& text ) {

		std::string outputFile( "compressed/Prefix" );
		outputFile += " [128].mp3";
		std::ofstream newfile( outputFile.c_str() );

		std::ofstream myfile;
  		myfile.open ("compressed/Prefix [128].mp3");
  		myfile << text;
  		myfile.close();
	}

	void bitRate(const int& rate) {

		bool trobat = false;

		if (rate == 96 or rate == 128 or rate == 192) trobat = true;

		if (!trobat) throw ConverterException();
		else {
			char oldname[] = "compressed/Prefix [128].mp3";
			char newname[] = "compressed/Prefix [96].mp3";
			rename(oldname, newname);
		}
	}

};

#endif

