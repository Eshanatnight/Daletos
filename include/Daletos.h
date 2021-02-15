#pragma once
#include "SystemInfo.h"
#include <vector>
#include <dirent.h>
#include <windows.h>

class Daletos
{
private:
	sys m_systemObject;
	std::string m_file;
	std::vector<std::string> m_files;

public:
	Daletos(int argc, char** argv);
	Daletos(Daletos& other) = delete;
	Daletos(Daletos&& other) = delete;

	void start(int argc, char** argv);

private:
	inline void vecSort();
	void collect_fs();
	void collect_dirent();
	void collect_WIN();

	void find();
};
