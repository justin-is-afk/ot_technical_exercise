#include "xml_to_html_test.hpp"
#include "xml_parse.hpp"
#include "html_table_generate.hpp"
#include "key_value_data.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include <gtest/gtest.h>

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////
// Test Functions
///////////////////////////////////////////////////////////////////////////////////////////////////
bool testConv(string xmlFileName, string htmlFileName, string dataSeriesName)
{
	bool ret = false;
	vector<unique_ptr<KeyValueStringData>> dataSeries;
	ret = xmlParse(xmlFileName, dataSeriesName, dataSeries);
	if(ret)
	{
		ret = htmlTableGenerate(htmlFileName, dataSeriesName, dataSeries);
	}
	return ret;
}

bool testValidXML()
{
	string xmlFileName = "data/cd_catalog.xml";
	string htmlFileName = "data/cd_catalog.html";
	string dataSeriesName = "CATALOG";
	return testConv(xmlFileName, htmlFileName, dataSeriesName);
}

bool testMalformedXML()
{
	string xmlFileName = "data/cd_catalog_malformed.xml";
	string htmlFileName = "data/cd_catalog_malformed.html";
	string dataSeriesName = "CATALOG";
	return testConv(xmlFileName, htmlFileName, dataSeriesName);
}

bool testEmptyXML()
{
	string xmlFileName = "data/cd_catalog_empty.xml";
	string htmlFileName = "data/cd_catalog_empty.html";
	string dataSeriesName = "CATALOG";
	return testConv(xmlFileName, htmlFileName, dataSeriesName);
}

bool testXMLVehicleData()
{
	string xmlFileName = "data/vehicle_data.xml";
	string htmlFileName = "data/vehicle_data.html";
	string dataSeriesName = "VEHICLES";
	return testConv(xmlFileName, htmlFileName, dataSeriesName);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// GTest Unit Tests
///////////////////////////////////////////////////////////////////////////////////////////////////
TEST(XML2HTML, valid_xml_file)
{
	EXPECT_EQ(true, testValidXML());
}

TEST(XML2HTML, malformed_xml)
{
	EXPECT_EQ(false, testMalformedXML());
}

TEST(XML2HTML, empty_xml)
{
	EXPECT_EQ(false, testEmptyXML());
}

TEST(XML2HTML, vehicle_data)
{
	EXPECT_EQ(true, testXMLVehicleData());
}