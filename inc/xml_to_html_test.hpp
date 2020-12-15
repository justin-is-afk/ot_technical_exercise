#ifndef __XML_TO_HTML_TEST_H__
#define __XML_TO_HTML_TEST_H__

#include <string>

//! testConv is the main test entry point for converting XML data to a HTML table
//! \param[in] xmlFileName the file name of the input XML file
//! \param[in] htmlFileName the file name of the output HTML file
//! \param[in] dataSeriesName the name of the data series to parse and convert
//! ret True on success, false otherwise
bool testConv(std::string xmlFileName, std::string htmlFileName, std::string dataSeriesName);

// Justin's Notes:
// These are just some basic unit test cases, more could and likely should be added
bool testValidXML();
bool testMalformedXML();
bool testEmptyXML();
bool testXMLVehicleData();

#endif // __XML_TO_HTML_TEST_H__