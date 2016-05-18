#ifndef ConverterGroup_hxx
#define ConverterGroup_hxx

#include <string>
#include <stdio.h>
#include <fstream>
//#include "ConverterGroup.hxx"
#include "LibFileSystem.hxx"
//#include "Converter.hxx"
#include "MP3Converter.hxx"
#include "OggConverter.hxx"


class ConverterGroup {
private:
	std::list<Converter> converterlist;

public:
	ConverterGroup() {}

	~ConverterGroup() {}

	void addConverter(const std::string& path, const int& rate) {
		bool trobat = false;

		if ( (rate == 96 or rate == 128 or rate == 192) && (path == "mp3" or path == "ogg")) trobat = true;

		if (!trobat) throw ConverterException();
		else{
			if(path == "mp3"){
				MP3Converter mp3converter;
				mp3converter.convert("masters/Master.wav","compressed/Prefix");

				if(rate == 96) mp3converter.bitRate(96);
				if(rate == 192) mp3converter.bitRate(192);

				converterlist.push_back(mp3converter);
			}
			else if(path == "ogg"){
				OggConverter oggconverter;
				oggconverter.convert("masters/Master.wav","compressed/Prefix");

				if(rate == 96) oggconverter.bitRate(96);
				if(rate == 192) oggconverter.bitRate(192);

				converterlist.push_back(oggconverter);
			}
		}
	}
};

#endif