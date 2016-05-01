#ifndef mp3converter_hxx
#define mp3converter_hxx

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <vector>
#include "Converter.cxx"


class directoryException : public std::exception {
public:
	const char * what() const throw() {
		return "The master file does not exist";
	}
};

class OggConverter {
private:
public:
	OggConverter() {}
	~OggConverter() {}

	void convert( const std::string& path, const std::string& file ) {

		//Check if path exists
		std::ifstream my_file(path.c_str());

		if ( my_file.good() ) {
			std::string outputFile( file );
			outputFile += " [128].ogg";
			std::ofstream newfile( outputFile.c_str() );
		} else throw directoryException();
	}

	void addContentToFile( const std::string& file,  const std::string& text ) {

		std::string outputFile( "compressed/Prefix" );
		outputFile += " [128].ogg";
		std::ofstream newfile( outputFile.c_str() );

		std::ofstream myfile;
  		myfile.open ("compressed/Prefix [128].ogg");
  		myfile << text;
  		myfile.close();
	}

	void bitRate(const int& rate) {
		char oldname[] = "compressed/Prefix [128].ogg";
		char newname[] = "compressed/Prefix [96].mp3";
		rename(oldname, newname);
		
	}

};


#endif