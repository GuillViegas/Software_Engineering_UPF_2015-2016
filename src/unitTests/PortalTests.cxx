#include "MiniCppUnit.hxx"
#include "LibFileSystem.hxx"
#include <fstream>
#include "Portal.hxx"

class PortalTests: public TestFixture<PortalTests>
{
public:
	TEST_FIXTURE( PortalTests ) {
		TEST_CASE( testPortal_createNewEmptyPortal );
		//TEST_CASE( testPortal_createNewEmptyPortal );

	}

	void testPortal_createNewEmptyPortal() {
		Portal portal;
		ASSERT_EQUALS(
			"No name", 
			portal.getPortalName()
		);

	}


};

REGISTER_FIXTURE( PortalTests )
