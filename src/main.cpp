#include "xml_to_html_test.hpp"
#include <string>
#include <gtest/gtest.h>
#include "loguru.hpp"

using namespace std;

int main(int argc, char **argv)
{
	/*
	assert(argc >= 2);
	const string fileName = argv[1];
	const string htmlFileName = "data/cd_catalog.html";
	const string dataSeriesName = "CATALOG";
	testConv(fileName, htmlFileName, dataSeriesName);
	*/
	loguru::init(argc, argv);
	LOG_F(INFO, "Begin XML 2 HTML testing...");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    
}