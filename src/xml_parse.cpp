#include "xml_parse.hpp"
#include "key_value_data.hpp"
#include "pugixml.hpp"
#include "loguru.hpp"
#include <fstream>

using namespace std;

// Justin's Notes:
// The exercise description called for only parsing one type of data, however I'm not a fan of
// writing "throw away" code. This function allows for a series of XML data entries to be parsed
// from the node `dataSeriesName`. It works on "CD catalogs" as well as other data types provided
// the right KeyValueStringData child class has been written. The child of KeyValueStringData defines 
// the key value pairs it stores, and thus can be used when parsing data from the series.
bool xmlParse(string fileName, string dataSeriesName, vector<unique_ptr<KeyValueStringData>>& data)
{
	pugi::xml_document xmlDoc;
	pugi::xml_parse_result result = xmlDoc.load_file(fileName.c_str());

	if(not result)
	{
		LOG_F(ERROR, "\"%s\" Invalid or malformed input data", fileName.c_str());
		return false;
	}
	if(not static_cast<bool>(xmlDoc.child(dataSeriesName.c_str())))
	{
		LOG_F(ERROR, "Node <%s> does not exist in \"%s\"", dataSeriesName.c_str(), fileName.c_str());
		return false;
	}

	// Justin's Notes:
	// If a "CD catalog" were to contain a series of vehicle data, instead of CD data, this fuction would still try to 
	// parse the data, but only actually parse data where the keys matched. In the example of <CD> and <CAR>, both
	// contain the key value pair <YEAR>. Thus if a CD catalog contained a <CAR>, it would be parsed as if
	// it were a <CD>. This could be avoided by checking that ALL keys match, or by checking the node name
	// itself (ie CD or CAR).

	//! \todo Store the node name inside the child of KeyValueStringData (ex CD, CAR, etc) and check each parsed
	//! node within the data series (CATALOG, VEHICLES, etc). Only add it to the series if the node name is expected.

	LOG_F(INFO, "XML \"%s\" parsed without errors, reading <%s>", fileName.c_str(), xmlDoc.child(dataSeriesName.c_str()).name());

	for(pugi::xml_node node: xmlDoc.child(dataSeriesName.c_str()))
	{
		auto newEntry = getNewEntry(dataSeriesName);
		for(unsigned int i = 0; i < newEntry->getNumValues(); ++i)
		{
			string key;
			if(newEntry->getKey(i, key))
			{
				const string val = node.child(key.c_str()).child_value();
				newEntry->setValue(i, val);
			}
			else
			{
				LOG_F(ERROR, "Unable to parse \"%s\"", key.c_str());
				return false;
			}
		}
		data.push_back(std::move(newEntry));
	}

	LOG_F(INFO, "<%s> data imported from \"%s\"", xmlDoc.child(dataSeriesName.c_str()).name(), fileName.c_str());
	return true;
}

// Justin's Notes:
// Depending on how many different types of data must be supported, this could be implemented via a factory
// where either the data series name (CATALOG) or data entry name (CD) would determine what type of KeyValueStringData
// to create. It would depend on the broader context of the feature or project.
unique_ptr<KeyValueStringData> getNewEntry(string dataSeriesName)
{
	if(dataSeriesName == "CATALOG")
	{
		unique_ptr<CDCatalogEntry> newEntry(new CDCatalogEntry());
		return newEntry;
	}
	//else if(dataSeriesName == "VEHICLES")
	unique_ptr<VehicleDataEntry> newEntry(new VehicleDataEntry());
	return newEntry;
}