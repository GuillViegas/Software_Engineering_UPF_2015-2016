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
		//TEST_CASE( testConvert_withMp3Converter );
		//TEST_CASE( testConvert_withOggConverter );
		//TEST_CASE( testConvert_withOggConverterAndDifferentBitrate );
		//TEST_CASE( testConvert_withMp3andOggConverters );
		//TEST_CASE( testConvert_withUnknownConverter );

	}

	void testConvert_withoutConverter(){
		ConverterGroup converterGroup;

		ASSERT_EQUALS(
			"",
			LibFileSystem::listDirectoryInOrder( "compressed" )
		);
	}

	void testConvert_withMp3Converter(){
		ConverterGroup converterGroup;
		converterGroup.addConverter( "mp3", 128 );

		ASSERT_EQUALS(
			"compressed/Prefix [128].mp3\n",
			LibFileSystem::listDirectoryInOrder( "compressed" )
		);
	}
};

REGISTER_FIXTURE( ConverterGroupTests )