#pragma once
#include "SystemInfo.h"
#include <vector>

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
	void ScreenInit();
	void collect_fs();
	void collect_WIN();

	void find();
};
