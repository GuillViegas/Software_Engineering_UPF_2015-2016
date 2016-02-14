#include "MiniCppUnit.hxx"
#include "Artist.hxx"

class ArtistTests : public TestFixture<ArtistTests>
{
public:
	TEST_FIXTURE( ArtistTest )
	{
		//TEST_CASE( testName_byDefault );
		//TEST_CASE( testName_afterModifying );
	}

	/*
	void testName_byDefault()
	{
		Artist artist;
		ASSERT_EQUALS( "-- Unnamed --", artist.title() );
	}

	void testName_afterModifying()
	{
		Artist artist;
		artist.name( "A Name" );
		ASSERT_EQUALS( "A Name", track.name() );
	}
	*/


}