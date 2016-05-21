#ifndef exception_hxx
#define exception_hxx

#include <string>
#include <exception>

class Exception : public std::exception {
public:
	virtual const char * what() const throw() { return ""; }

};

// ---------------------------------------------------------------------------

class trackException : public Exception {
public:
	const char * what() const throw() {
		return "The track does not exist";
	}
};

// ---------------------------------------------------------------------------


class albumException : public Exception {
public:
	const char * what() const throw() {
		return "The album does not exist";
	}
};

// ---------------------------------------------------------------------------

class directoryException : public Exception {
public:
	const char * what() const throw() {
		return "The master file does not exist";
	}
};

// ---------------------------------------------------------------------------

class ConverterException : public Exception {
public:
	const char * what() const throw() {
		return "Unsupported format";
	}
};

// ---------------------------------------------------------------------------

class artistException : public Exception {
public:
	const char * what() const throw() {
		return "The artist does not exist";
	}
};

// ---------------------------------------------------------------------------

class styleException : public Exception {
public:
	const char * what() const throw() {
		return "The style does not exist";
	}
};

// ---------------------------------------------------------------------------

class userException : public Exception {
public:
	const char * what() const throw() {
		return "The user does not exist";
	}
};

// ---------------------------------------------------------------------------


#endif
