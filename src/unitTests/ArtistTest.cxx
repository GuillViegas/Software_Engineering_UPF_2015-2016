#include "MiniCppUnit.hxx"
#include "Artist.hxx"

class ArtistTest : public TestFixture<ArtistTest>
{
public:
	TEST_FIXTURE( ArtistTest )
	{
		TEST_CASE( testName_byDefault );
		//TEST_CASE( testName_afterModifying );
		//TEST_CASE( testGroup_byDefault );
		//TEST_CASE( testGroup_afterModifying );
		//TEST_CASE( testSolo_byDefault );
		//TEST_CASE( testSolo_afterModifying );
	}

	
	void testName_byDefault()
	{
		Artist artist;
		ASSERT_EQUALS( "-- No name --", artist.name() );
	}

	/*
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

	void testSolo_byDefault()
	{
		Artist artist;
		ASSERT_EQUALS( false , track.isSolo() );
	}

		void testSolo_afterModifying()
	{
		Artist artist;
		artist.solo();
		ASSERT_EQUALS( true , track.isSolo() );
	}
	*/


};