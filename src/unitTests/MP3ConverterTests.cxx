#include "MiniCppUnit.hxx"
#include "LibFileSystem.hxx"
#include <fstream>

#include "MP3Converter.hxx"
//#include "Converter.hxx"

class MP3ConverterTests : public TestFixture<MP3ConverterTests>
{
public:
	TEST_FIXTURE ( MP3ConverterTests )
	{
		TEST_CASE( testConvert_generateFile );
		TEST_CASE( testConvert_generateContent );
		TEST_CASE( testConvert_withDifferentBitrate );
		TEST_CASE( testConvert_withUnsupportedFormat );
		TEST_CASE( testConvert_withInexistentMaster );
		TEST_CASE( testConvert_polymorphicCall );

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
	
	void testConvert_generateContent() 
	{

		MP3Converter converter;

		createMasterFile( "Master.wav", 50);
		converter.convert( "masters/Master.wav", "compressed/Prefix" );
		converter.addContentToFile("compressed/Prefix", "MP3 extracted from 'masters/Master.wav' at 128 bps and length 50s.");

		ASSERT_EQUALS(
			"MP3 extracted from 'masters/Master.wav' at 128 bps and length 50s.\n",
			LibFileSystem::fileContent( "compressed/Prefix [128].mp3" )
		);
	}

	
	void testConvert_withDifferentBitrate() 
	{
		MP3Converter converter;

		createMasterFile( "Master.wav", 50);
		converter.convert( "masters/Master.wav", "compressed/Prefix" );
		converter.bitRate(96);

		ASSERT_EQUALS(
			"compressed/Prefix [96].mp3\n",
			LibFileSystem::listDirectoryInOrder( "compressed" )
		);

	}
	
	
	void testConvert_withUnsupportedFormat() 
	{
		MP3Converter converter;
		createMasterFile( "Master.wav", 50);
		converter.convert( "masters/Master.wav", "compressed/Prefix" );
		
		try 
		{
			converter.bitRate(72);
			FAIL( "An exception should be caught!" );
		}
		catch (std::exception & e)
		{
			ASSERT_EQUALS( "Unsupported format", e.what() );
		}
	}

	
	void testConvert_withInexistentMaster() 
	{
		MP3Converter converter;
	try 
	{
		converter.convert( "master/Master.wav", "compressed/Prefix" );
		FAIL( "An exception should be caught!" );
	}
	catch ( std::exception & e)
	{
		ASSERT_EQUALS( "The master file does not exist", e.what() );
	}

	}


	void testConvert_polymorphicCall() 
	{
		MP3Converter mp3converter;
		Converter & converter = mp3converter;

		createMasterFile( "Master.wav", 50);
		converter.convert( "masters/Master.wav", "compressed/Prefix" );

		ASSERT_EQUALS(
			"compressed/Prefix [128].mp3\n",
			LibFileSystem::listDirectoryInOrder( "compressed" )
		);
	}


};

REGISTER_FIXTURE( MP3ConverterTests )