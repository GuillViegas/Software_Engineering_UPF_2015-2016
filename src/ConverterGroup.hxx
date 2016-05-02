#ifndef ConverterGroup_hxx
#define ConverterGroup_hxx

#include <string>

#include "Converter.cxx"

class ConverterGroup {
private:
	std::list<Converter> converterlist;

public:
	ConverterGroup() {}

	~ConverterGroup() {}

	void addConverter(const std::string& format, const int& rate) {
		
	}
};

#endif