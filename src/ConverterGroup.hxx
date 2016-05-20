#ifndef ConverterGroup_hxx
#define ConverterGroup_hxx

#include <string>
#include <stdio.h>
#include <fstream>
#include "LibFileSystem.hxx"
#include "Converter.hxx"
#include "MP3Converter.hxx"
#include "OggConverter.hxx"


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

				if (rate == 96) mp3converter.bitRate(96);
				else if (rate == 128) mp3converter.bitRate(128);
				else mp3converter.bitRate(192);

				converterlist.push_back(mp3converter);

			} else if (path == "ogg") {

				OggConverter oggconverter;
				oggconverter.convert("masters/Master.wav","compressed/Prefix");

				if (rate == 96) oggconverter.bitRate(96);
				else if (rate == 128) oggconverter.bitRate(128);
				else oggconverter.bitRate(192);

				converterlist.push_back(oggconverter);
			
			} else throw ConverterException();

		
		} else throw ConverterException();

	}
};

#endif
