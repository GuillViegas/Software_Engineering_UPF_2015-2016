#ifndef ConverterGroup_hxx
#define ConverterGroup_hxx

#include <string>
#include <stdio.h>
#include <fstream>
#include "LibFileSystem.hxx"
#include "Converter.hxx"
#include "MP3Converter.hxx"
#include "OggConverter.hxx"
#include "Exception.hxx"


class ConverterGroup {
private:
	std::list<Converter> converterlist;

public:
	ConverterGroup() {}

	~ConverterGroup() {}

	void addConverter(const std::string& path, const int& rate) {

		if ( rate == 96 or rate == 128 or rate == 192) {
			
			if (path == "mp3") {
				
				MP3Converter mp3converter;
				mp3converter.convert("masters/Master.wav","compressed/Prefix");
				mp3converter.bitRate(rate);
				converterlist.push_back(mp3converter);

			} else if (path == "ogg") {

				OggConverter oggconverter;
				oggconverter.convert("masters/Master.wav","compressed/Prefix");
				oggconverter.bitRate(rate);
				converterlist.push_back(oggconverter);
			
			} else throw ConverterException();

		
		} else throw ConverterException();

	}
};

#endif
