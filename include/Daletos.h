#pragma once
#include "SystemInfo.h"
#include <vector>

class Daletos
{
private:
	sys m_systemObject;
	std::string m_fileName;
	std::vector<std::string> m_files;
	std::vector<std::string> m_argv;

public:
	Daletos();
	Daletos(Daletos& other) = delete;
	Daletos(Daletos&& other) = delete;

	void start();

private:
	inline void vecSort();
	void ScreenInit();
	void collect_fs();
	void collect_WIN();
	void helpSearch();
	void appHelp();
	void FindAndList();
	void paremHandling();
};
