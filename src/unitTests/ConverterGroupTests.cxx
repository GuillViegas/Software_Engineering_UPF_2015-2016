#include <fstream>
#include "MiniCppUnit.hxx"
#include "ConverterGroup.hxx"
#include "LibFileSystem.hxx"
#include "MP3Converter.cxx"
#include "OggConverter.cxx"
#include "Converter.cxx"

class ConverterGroupTests : public TestFixture<ConverterGroupTests>
{
public:
	TEST_FIXTURE ( ConverterGroupTests )
	{
		TEST_CASE( testConvert_withoutConverter );
		TEST_CASE( testConvert_withMp3Converter );
		TEST_CASE( testConvert_withOggConverter );
		//TEST_CASE( testConvert_withOggConverterAndDifferentBitrate );
		//TEST_CASE( testConvert_withMp3andOggConverters );
		//TEST_CASE( testConvert_withUnknownConverter );

	}

		/**
	 * setUp is automatically called before each test case
	 */
	void setUp()
	{
		LibFileSystem::createNetDirectory( "masters" );
		LibFileSystem::createNetDirectory( "compressed" );
		LibFileSystem::createNetDirectory( "config" );
	}

	/**
	 * tearDown is automatically called after each test case
	 */
	void tearDown()
	{
		LibFileSystem::cleanupDirectory( "masters" );
		LibFileSystem::cleanupDirectory( "compressed" );
		LibFileSystem::cleanupDirectory( "config" );
	}

	void createMasterFile( const std::string & name, int duration )
	{
		std::string completeName( "masters/" );
		completeName += name;
		std::ofstream os( completeName.c_str() );
		os << duration << std::endl;
	}

	void testConvert_withoutConverter(){
		ConverterGroup converterGroup;

		ASSERT_EQUALS(
			"",
			LibFileSystem::listDirectoryInOrder( "compressed" )
		);
	}

	void testConvert_withMp3Converter(){
		createMasterFile( "Master.wav", 50);
		ConverterGroup converterGroup;
		converterGroup.addConverter( "mp3", 128 );

		ASSERT_EQUALS(
			"compressed/Prefix [128].mp3\n",
			LibFileSystem::listDirectoryInOrder( "compressed" )
		);
	}

	void testConvert_withOggConverter(){
		ConverterGroup converterGroup;
		converterGroup.addConverter( "ogg", 128 );

		ASSERT_EQUALS(
			"compressed/Prefix [128].ogg\n",
			LibFileSystem::listDirectoryInOrder( "compressed" )
		);
	}

	void testConvert_withOggConverterAndDifferentBitrate(){
		ConverterGroup converterGroup;
		converterGroup.addConverter( "ogg", 96 );

		ASSERT_EQUALS(
			"compressed/Prefix [96].ogg\n",
			LibFileSystem::listDirectoryInOrder( "compressed" )
		);
	}

	void testConvert_withMp3andOggConverters(){
		ConverterGroup converterGroup;
		converterGroup.addConverter( "mp3", 128);
		converterGroup.addConverter( "ogg", 128);

		ASSERT_EQUALS(
			"compressed/Prefix [128].mp3\n"
			"compressed/Prefix [128].ogg\n",
			LibFileSystem::listDirectoryInOrder( "compressed" )
		);
	}

	void testConvert_withUnknownConverter(){
		ConverterGroup converterGroup;

		try 
		{
			converterGroup.addConverter( "wma", 128);
			FAIL( "An exception should be caught!" );
		}
		catch (std::exception & e)
		{
			ASSERT_EQUALS( "Unsupported format", e.what() );
		}
	}


};

REGISTER_FIXTURE( ConverterGroupTests )