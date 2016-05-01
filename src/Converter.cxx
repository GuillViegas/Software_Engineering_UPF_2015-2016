#ifndef converter_hxx
#define converter_hxx

#include <string>

class Converter {
private:

public:
	virtual ~Converter() {}
	virtual void convert( const std::string& path, const std::string& file ) {}
	virtual void addContentToFile( const std::string& file,  const std::string& text ) {}
	virtual void bitRate(const int& rate) {}
};

#endif