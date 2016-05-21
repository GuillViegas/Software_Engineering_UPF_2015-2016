#include "MiniCppUnit.hxx"
#include "Style.hxx"

class StyleTests : public TestFixture<StyleTests>
{
public:
	TEST_FIXTURE( StyleTests) {
		TEST_CASE( testStyle_createNewStyle );
		// TEST_CASE( testStyle_addUsertoSubscribersList );
	}

	void testStyle_createNewStyle() 
	{
		Style style("house");
		ASSERT_EQUALS(
			"house", 
			style.getNameStyle()
		);
	}

};

REGISTER_FIXTURE( StyleTests) 
