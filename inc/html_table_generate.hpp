#ifndef __HTMP_TABLE_GENERATE_H__
#define __HTMP_TABLE_GENERATE_H__

#include <string>
#include <vector>
#include <memory>

class KeyValueStringData;

//! Generate an HTML table based on the provided vector of data entries using the string keys 
//! provided by the KeyValueStringData entries as the columns and the values for each entry as the rows.
//! \note Malformed data entries will be ignored.
//! \param[in] fileName the name of the output HTML file
//! \param[in] dataSeriesName the name of the data series used to generate the HTML table
//! \param[in] data a vector of unique pointers to KeyValueStringData, where the data that will populated the table is contained.
//! \ret true on success, false otherwise
bool htmlTableGenerate(std::string fileName, std::string tableName, std::vector<std::unique_ptr<KeyValueStringData>>& data);

#endif // __HTMP_TABLE_GENERATE_H__