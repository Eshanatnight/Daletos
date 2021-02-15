#include "str_manip.h"

inline bool ends_with(std::string const& value, std::string const& ending)
{
	if (ending.size() > value.size())
		return false;

	return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

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