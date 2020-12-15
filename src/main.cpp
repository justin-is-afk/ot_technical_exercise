#include "xml_to_html_test.hpp"
#include <string>
#include <gtest/gtest.h>
#include "loguru.hpp"

using namespace std;

int main(int argc, char **argv)
{
	assert(argc >= 2);
	const string fileName = argv[1];
	LOG_F(INFO, "Begin XML to HTML Table conversion of \"%s\"", fileName.c_str());

	// Justin's Notes:
	// As the exercise description called for an executable that would take in a filename,
	// I've "hard-coded" these values. They should however be taked as inputs, just as
	// the input XML file name is.
	const string htmlFileName = "data/table.html";
	const string dataSeriesName = "CATALOG";
	testConv(fileName, htmlFileName, dataSeriesName);

	// Justin's Notes:
	// As the exercise called for "engineering best practices" I thought it appropriate to
	// include some unit tests, as well as a logger. The logger simply outputs to the console
	// for simplicity, but could be set to instead log to a file. There should be a pull request 
	// open in the github repo to change `main` to instead run the google test unit tests that
	// I've included in `xml_to_html_test.cpp`.
	//LOG_F(INFO, "Begin XML to HTML Table testing...");
	//testing::InitGoogleTest(&argc, argv);
	//return RUN_ALL_TESTS();
	return 0;
}