#ifndef mp3converter_hxx
#define mp3converter_hxx

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <vector>

class MP3ConverterException : public std::exception {
public:
	const char * what() const throw() {
		return "Unsupported format";
	}
};

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

		if (!trobat) throw MP3ConverterException();
		else {
			char oldname[] = "compressed/Prefix [128].mp3";
			char newname[] = "compressed/Prefix [96].mp3";
			rename(oldname, newname);
		}
	}

};

#endif

