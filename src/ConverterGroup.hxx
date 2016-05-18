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
		if(path == "mp3" && rate == 128 ){
			MP3Converter mp3converter;
			mp3converter.convert("masters/Master.wav","compressed/Prefix");
			converterlist.push_back(mp3converter);
		}
		if(path == "ogg" && rate == 128){
			OggConverter oggconverter;
			oggconverter.convert("masters/Master.wav","compressed/Prefix");
			converterlist.push_back(oggconverter);
		}
	}
};

#endif