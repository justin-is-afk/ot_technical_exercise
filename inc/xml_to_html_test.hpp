#ifndef __XML_TO_HTML_TEST_H__
#define __XML_TO_HTML_TEST_H__

#include <string>

bool testConv(std::string xmlFileName, std::string htmlFileName, std::string dataSeriesName);
bool testValidXML();
bool testMalformedXML();
bool testEmptyXML();
bool testXMLVehicleData();

#endif // __XML_TO_HTML_TEST_H__