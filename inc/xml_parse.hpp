#ifndef __XML_PARSE_H__
#define __XML_PARSE_H__

#include <string>
#include <vector>
#include <memory>

class KeyValueStringData;

//! Parse the XML file and fill data with a set of entries comprised of key-value pairs,
//! using the string keys provided by the KeyValueStringData entries themselves.
//! \note The XML file's data series should only contain data entries of one type (ie only one type of node,
//! in the use case of this coding exercise that would be "CD"). Malformed data and/or entries will
//! be ignored.
//! \param[in] fileName the name of the input XML file
//! \param[in] dataSeriesName the name of the data series being parsed
//! \param[in] data a vector of unique pointers, where data entires will be filled as the XML file is parsed
//! \ret true on success, false otherwise
bool xmlParse(std::string fileName, std::string dataSeriesName, std::vector<std::unique_ptr<KeyValueStringData>>& data);

std::unique_ptr<KeyValueStringData> getNewEntry(std::string dataSeriesName);

#endif // __XML_PARSE_H__