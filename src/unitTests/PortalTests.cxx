#include "MiniCppUnit.hxx"
#include "LibFileSystem.hxx"
#include <fstream>
#include "Portal.hxx"

class PortalTests: public TestFixture<PortalTests>
{
public:
	TEST_FIXTURE( PortalTests ) {
		TEST_CASE( testPortal_createNewEmptyPortal );
		TEST_CASE( testPortal_createNewPortal );

	}

	void testPortal_createNewEmptyPortal() {
		Portal portal;
		ASSERT_EQUALS(
			"", 
			portal.getPortalName()
		);

	}

	void testPortal_createNewPortal() {
		Portal portal("Portal Test", "This is a test portal message");
		ASSERT_EQUALS(
			"Portal Test\n" 
			"This is a test portal message", 
			portal.getInfoFromPortal()
		);

	}


};

REGISTER_FIXTURE( PortalTests )
