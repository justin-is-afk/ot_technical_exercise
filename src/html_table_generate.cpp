#include "html_table_generate.hpp"
#include "key_value_data.hpp"
#include "loguru.hpp"
#include <fstream>

using namespace std;

bool htmlTableGenerate(string fileName, string tableName, vector<unique_ptr<KeyValueStringData>>& data)
{
	if(not (data.size() > 0))
	{
		LOG_F(ERROR, "Input data is empty");
		return false;	
	}

	LOG_F(INFO, "Generating HTML Table \"%s\"", fileName.c_str());

	fstream outFile;
	outFile.open(fileName, fstream::out);
	outFile << "<!DOCTYPE html>" << endl;
	outFile << "<h2>" << tableName << "</h2>" << endl;
	outFile << "<table style=\"width:80%\">" << endl;

	// Generate columns
	outFile << "  <tr>" << endl;
	for(unsigned int i = 0; i < data.at(0)->getNumValues(); ++i)
	{
		string key;
		data.at(0)->getKey(i, key);
		outFile <<"    <td><b>" << key << "</b></td>" << endl;
	}
	outFile << "  </tr>" << endl;

	// Generate rows
	for(auto& entry : data)
	{
		outFile << "  <tr>" << endl;
		for(unsigned int i = 0; i < entry->getNumValues(); ++i)
		{
			string val;
			entry->getValue(i, val);
			outFile << "    <td>" << val << "</td>" << endl;
		}
		outFile << "  </tr>" << endl;
	}
	outFile.close();

	LOG_F(INFO, "Successfully generated <%s> table \"%s\"", tableName.c_str(), fileName.c_str());
	return true;
}