#include "MiniCppUnit.hxx"
#include "Style.hxx"

class StyleTests : public TestFixture<StyleTests>
{
public:
	TEST_FIXTURE( StyleTests) {
		TEST_CASE( testStyle_createNewStyle );
		TEST_CASE( testStyle_addUsertoSubscribersList );
	}

	void testStyle_createNewStyle() 
	{
		Style style("house");
		ASSERT_EQUALS(
			"house", 
			style.getNameStyle()
		);
	}

	void testStyle_addUsertoSubscribersList() 
	{
		Style style("classic");
		User user("elena", "elena@gmail.com");
		style.addUsertoSubscribers(user);
		ASSERT_EQUALS(
			"elena", 
			style.subscribersList()
		);

	}

};

REGISTER_FIXTURE( StyleTests) 
