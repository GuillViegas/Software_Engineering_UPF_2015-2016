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

	void addContentToFile( const std::string& file,  const std::string& text ) {

		std::string outputFile( "compressed/Prefix" );
		outputFile += " [128].mp3";
		std::ofstream newfile( outputFile.c_str() );

		std::ofstream myfile;
  		myfile.open ("compressed/Prefix [128].mp3");
  		myfile <<  text;
  		myfile.close();
		
		//std::string pathFile ("/masters");
		//pathFile += file;
		//std::ofstream myfile( file );
  		//myfile.open( pathFile.c_str() );
  		//myfile.open( "compressed/Prefix [128].mp3" );
  		//myfile << text;
  		//myfile.close();
	}

	//void bitRate(const int & rate) {}

};

#endif

