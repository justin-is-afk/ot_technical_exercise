#include "xml_parse.hpp"
#include "key_value_data.hpp"
#include "pugixml.hpp"
#include "loguru.hpp"
#include <fstream>

using namespace std;

bool xmlParse(string fileName, string dataSeriesName, vector<unique_ptr<KeyValueStringData>>& data)
{
	pugi::xml_document xmlDoc;
	pugi::xml_parse_result result = xmlDoc.load_file(fileName.c_str());

	if(not result)
	{
		LOG_F(ERROR, "\"%s\" Invalid or malformed input data\n", fileName.c_str());
		return false;
	}

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

	LOG_F(INFO, "<%s> imported data from \"%s\"", xmlDoc.child(dataSeriesName.c_str()).name(), fileName.c_str());
	return true;
}

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