#include "SystemInfo.h"

// default constructor
sys::sys() :
	m_cwd(this->get_current_dir())
{}





std::string get_current_dir()
{
	TCHAR buffer[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, buffer, MAX_PATH);
	std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");
	std::wstring temp(buffer);
	std::string dir(temp.begin(), temp.end());
	dir = dir.substr(0, pos);
	return dir;
}