#include "MiniCppUnit.hxx"
#include "User.hxx"

class UserTests : public TestFixture<UserTests>
{
public:
	TEST_FIXTURE( UserTests ) {
		TEST_CASE( testUser_createEmptyNewUser );
		TEST_CASE( testUser_afterModifyingName );
		TEST_CASE( testUser_afterModifyingMail );
		//TEST_CASE( testUser_createNewUser );
	}

	void testUser_createEmptyNewUser() 
	{
		User user;
		ASSERT_EQUALS(
			"No name", 
			user.getName()
		);
	}

		void testUser_afterModifyingName() 
	{
		User user;
		user.setName("Louise");
		ASSERT_EQUALS(
			"Louise", 
			user.getName()
		);

	}

	void testUser_afterModifyingMail() 
	{
		User user;
		user.setMail("test@gmail.com");
		ASSERT_EQUALS(
			"test@gmail.com",
			user.getMail()
		);

	}

	void testUser_createNewUser() 
	{
		User user;
		user.setName("John");
		user.setMail("john@gmail.com");
		ASSERT_EQUALS(
			"John john@gmail.com\n", 
			user.getInfo()
		);

	}

};

REGISTER_FIXTURE( UserTests ) 
