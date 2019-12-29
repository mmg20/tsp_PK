#include "trim.h"

string trim(const string& str)
{
	size_t first = str.find_first_not_of(' ');
	if (first == string::npos)
		return "";
	std::size_t last = str.find_last_not_of(' ');

	return str.substr(first, last - first + 1);
}