#include "SystemInfo.h"
#include <windows.h>
#include <cstdio>
#include <cmath>

#pragma comment(lib, "user32.lib")

// default constructor
sys::sys()
	: m_cwd(get_current_dir())
{
	// For processor core data
	SYSTEM_INFO m_siSysInfo;
	GetSystemInfo(&m_siSysInfo);
	m_cores = m_siSysInfo.dwNumberOfProcessors;

	// For Ram Data
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	m_ram = ceil(statex.ullTotalPhys / (1024 * 1024 * 1024)) + 1;
}

std::string sys::get_current_dir()
{
	TCHAR buffer[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, buffer, MAX_PATH);
	std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");
	std::wstring temp(buffer);
	std::string dir(temp.begin(), temp.end());
	dir = dir.substr(0, pos);
	return dir;
}