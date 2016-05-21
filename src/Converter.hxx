#ifndef converter_hxx
#define converter_hxx

#include <string>
#include "Exception.hxx"


// class directoryException : public std::exception {
// public:
// 	const char * what() const throw() {
// 		return "The master file does not exist";
// 	}
// };

// class ConverterException : public std::exception {
// public:
// 	const char * what() const throw() {
// 		return "Unsupported format";
// 	}
// };

class Converter {
private:

public:
	Converter() {}
	virtual ~Converter() {}
	virtual void convert( const std::string& path, const std::string& file ) {}
	virtual void addContentToFile( const std::string& file,  const std::string& text ) {}
	virtual void bitRate(const int& rate) {}
};

#endif
