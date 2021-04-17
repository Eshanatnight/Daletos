#include "str_manip.h"

/* checks weather a string ends with a specific substr or not (abstracted) */
inline bool ends_with(std::string const& value, std::string const& ending)
{
	if (ending.size() > value.size())
		return false;

	return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

/* Converts a wchar_t to a string */
std::string wchar_t2string(const wchar_t* wchar)
{
	std::string str = "";
	int index = 0;
	while (wchar[index] != 0)
	{
		str += (char)wchar[index];
		++index;
	}
	return str;
}

/* Converts a string to a wchar_t */
wchar_t* string2wchar_t(const std::string& str)
{
	wchar_t wchar[260];
	int index = 0;
	while (index < str.size())
	{
		wchar[index] = (wchar_t)str[index];
		++index;
	}
	wchar[index] = 0;
	return wchar;
}

/* Checks weather a container with strings is empty or not */
bool isEmpty(const std::vector<std::string>& container)
{
	bool check = true;
	for (const std::string& elem : container)
	{
		if (!elem.empty())
			check = false;
		break;
	}
	return check;
}