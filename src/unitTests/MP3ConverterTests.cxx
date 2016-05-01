#include "MiniCppUnit.hxx"
#include "LibFileSystem.hxx"
#include <fstream>
#include "MP3Converter.cxx"

class MP3ConverterTests : public TestFixture<MP3ConverterTests>
{
public:
	TEST_FIXTURE ( MP3ConverterTests )
	{
		TEST_CASE( testConvert_generateFile );
		//TEST_CASE( testConvert_generateContent );
		//TEST_CASE( testConvert_withDifferentBitrate );
		//TEST_CASE( testConvert_withUnsupportedFormat );
		//TEST_CASE( testConvert_withInexistentMaster );
		//TEST_CASE( testConvert_polymorphicCall );

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
	
	
	void testConvert_generateFile() 
	{
		MP3Converter converter;

		createMasterFile( "Master.wav", 50);
		converter.convert( "masters/Master.wav", "compressed/Prefix" );

		ASSERT_EQUALS(
			"compressed/Prefix [128].mp3\n",
			LibFileSystem::listDirectoryInOrder( "compressed" )
		);

	}
	/*
	void testConvert_generateContent() {}
	void testConvert_withDifferentBitrate() {}
	void testConvert_withUnsupportedFormat() {}
	void testConvert_withInexistentMaster() {}
	void testConvert_polymorphicCall() {}
	*/

};

REGISTER_FIXTURE( MP3ConverterTests )