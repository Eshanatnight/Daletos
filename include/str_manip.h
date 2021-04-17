#pragma once
#include <string>
#include <vector>

inline bool ends_with(std::string const& value, std::string const& ending);

std::string wchar_t2string(const wchar_t* wchar);

wchar_t* string2wchar_t(const std::string& str);

bool isEmpty(const std::vector<std::string>& container);
