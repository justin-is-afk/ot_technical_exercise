#ifndef __KEY_VALUE_PAIR_H__
#define __KEY_VALUE_PAIR_H__

#include <string>
#include <vector>
#include <algorithm>

//! KeyValueData is a generic data container which encapsulates a number of values
//! associated with a string key, for a given object. 
//! \note An example use of KeyValueData could be to store vehicle data. The values 
//! a user may wish to store could be "MODEL", "MAKE", "YEAR", etc. - these would be the
//! keys associated with the underliny data. KeyValueData provides the interface to access 
//! the values by their string key, as well as provides access to the "keys" themselves. 
//! This means code working with a child of KeyValueData need not know or care about the 
//! specific values or their keys; just that there exist some number (N) of key-value pairs.
template<typename T>
class KeyValueData
{
public:
	//! Get the number of key-value pairs
	//! \ret the number of key-value pairs
	unsigned int getNumValues()
	{
		return N;
	}

	//! Get the string key at index, if the index is valid
	//! \param[in] i the index of the key
	//! \param[out] ret The variable where the string key will be returned
	//! \ret true on success, false otherwise
	bool getKey(unsigned int i, std::string& ret)
	{
		if(i < keys.size())
		{
			ret = keys.at(i);
			return true;
		}
		return false;
	}

	//! Set the value at index, if the index is valid
	//! \param[in] i the index of the value
	//! \param[in] set the value to set
	//! \ret true on success, false otherwise
	bool setValue(unsigned int i, const T set)
	{
		if(i < values.size())
		{
			values.at(i) = set;
			return true;
		}
		return false;
	}

	//! Get the value at index, if the index is valid
	//! \param[in] i the index of the value
	//! \param[out] ret The variable where the value will be returned
	//! \ret true on success, false otherwise
	bool getValue(unsigned int i, T& ret)
	{
		if(i < values.size())
		{
			ret = values.at(i);
			return true;
		}
		return false;
	}

	//! Searches for the string key in keys, and returns the assocaited value if found
	//! \param[in] key The key associated with the value desired
	//! \param[out] ret The variable where the value will be returned
	//! \ret true on success, false otherwise
	bool getValueByKey(std::string key, T& ret)
	{
		auto it = std::find(keys.begin(), keys.end(), key);
		if(it != keys.end())
		{
			unsigned int index = std::distance(keys.begin(), it);
			ret = values.at(index);
			return true;
		}
		return false;
	}

	~KeyValueData() = default;

protected:
	//! KeyValueData's constructor is private in order to enforce
	//! the use of derivative child classes which specify the
	//! string keys used to acces their data values.
	//! \note The children of KeyValueData should set `keys`
	//! upon construction
	KeyValueData(const unsigned int n);

	//! keys stores the string keys associated with the stored data
	//! at the same index as the value.
	std::vector<std::string> keys;
	//! values stores the actual data value associated with the string
	//! key at the same index as the key.
	std::vector<T> values;
	//! N is the size of the vectors used to contain the keys and values.
	const unsigned int N;
};

//! KeyValueStringData is container of KeyValueData, where
//! the data values are of type string.
class KeyValueStringData : public KeyValueData<std::string>
{
public:
	KeyValueStringData(const unsigned int n);
	~KeyValueStringData() = default;
};

//! CDCatalogEntry is container of KeyValueStringData,
//! specific to a CD catalog entry.
class CDCatalogEntry : public KeyValueStringData
{
public:
	CDCatalogEntry();
	~CDCatalogEntry() = default;
};

//! VehicleDataEntry is container of KeyValueStringData,
//! specific to a vehicle data series.
class VehicleDataEntry : public KeyValueStringData
{
public:
	VehicleDataEntry();
	~VehicleDataEntry() = default;
};

#endif // __KEY_VALUE_PAIR_H__
