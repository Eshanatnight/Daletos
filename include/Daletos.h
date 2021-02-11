#pragma once
#include "SystemInfo.h"
#include <array>
#include <vector>
#include <filesystem>

class Daletos
{
private:
	sys m_systemObject;
	std::string m_file;
	// ! std::array m_argv might be useless
	// ? Maybe depricated
	std::array<std::string, 7> m_argv {"-h", "--help", "-s", "--search", "-fs", "--fast-search", "search"};
	std::vector<std::string> m_files;

public:
	Daletos(int argc, char** argv);
	Daletos(Daletos& other) = delete;
	Daletos(Daletos&& other) = delete;

	void start(int argc, char** argv);

private:
	void search_fs(const std::string& fileName);
};
