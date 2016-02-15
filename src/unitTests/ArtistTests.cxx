/* Final version for lab session 2 */
#include "MiniCppUnit.hxx"
#include "Artist.hxx"

class ArtistTests : public TestFixture<ArtistTests>
{
public:
	TEST_FIXTURE( ArtistTests )
	{
		TEST_CASE( testName_byDefault );
		TEST_CASE( testName_afterModifying );
		TEST_CASE( testGroup_byDefault );
		TEST_CASE( testGroup_afterModifying );
		TEST_CASE( testDescription_getInfo );

	}

	
	void testName_byDefault()
	{
		Artist artist;
		ASSERT_EQUALS( "-- No name --", artist.name() );
	}

	
	void testName_afterModifying()
	{
		Artist artist;
		artist.name( "A Name" );
		ASSERT_EQUALS( "A Name", artist.name() );
	}

	
	void testGroup_byDefault()
	{
		Artist artist;
		ASSERT_EQUALS( false , artist.isGroup() );
	}

	
	void testGroup_afterModifying()
	{
		Artist artist;
		artist.group();
		ASSERT_EQUALS( true , artist.isGroup() );
	}

	void testDescription_getInfo(){

		Artist artist;
		artist.name( "A Name" );
		ASSERT_EQUALS("A Name [solo] \n", artist.description() );
	}


};

REGISTER_FIXTURE( ArtistTests )
