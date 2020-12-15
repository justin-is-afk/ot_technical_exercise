#include "key_value_data.hpp"

using namespace std;

template<typename T>
KeyValueData<T>::KeyValueData(const unsigned int n) : N(n) 
{
	keys.reserve(N);
	values.reserve(N);
}

KeyValueStringData::KeyValueStringData(const unsigned int n) : 
	KeyValueData<std::string>(n) 
{

}

CDCatalogEntry::CDCatalogEntry() : 
	KeyValueStringData(6)
{
	keys = {"TITLE", "ARTIST", "COMPANY", "COUNTRY", "YEAR", "PRICE"};
	values = {"", "", "", "", "", ""};
}

VehicleDataEntry::VehicleDataEntry() : 
	KeyValueStringData(3)
{
	keys = {"MAKE", "MODEL", "YEAR"};
	values = {"", "", ""};
}
