#include "Daletos.h"

// fmt Library
#include "fmt/color.h"
#include "fmt/core.h"
#include "fmt/ostream.h"

// Str Manip Header
#include "str_manip.h"

// Other Stuff
#include <windows.h>
#include <cstring>
#include <iostream>
#include <utility>
#include <filesystem>
#include <algorithm>
#include <fstream>

Daletos::Daletos(int argc, char** argv)
	: m_file(argv[3])
{
	m_files.reserve(10);
}

void Daletos::ScreenInit()
{
	for (int i = 0; i <= 70; i++)
	{
		fmt::print("*");
	} fmt::print("\n");

	fmt::print(fg(fmt::color::deep_pink) | bg(fmt::color::gainsboro) | fmt::emphasis::bold, "**\tDaletos [Starting.....]\n");

	for (int i = 0; i <= 70; i++)
	{
		fmt::print("*");
	} fmt::print("\n");

	Sleep(700);
	system("cls");

	for (int i = 0; i <= 70; i++)
	{
		fmt::print("*");
	} fmt::print("\n");

	fmt::print(fg(fmt::color::deep_pink) | bg(fmt::color::gainsboro) | fmt::emphasis::bold, "**\tDaletos\t");
	fmt::print(fg(fmt::color::green) | fmt::emphasis::bold, "[Status: Online]\n");
	//std::cout << "Current Dir: " << m_system
	fmt::print("Current Directory:\t {} \n", m_systemObject.m_cwd);
	fmt::print(fmt::emphasis::bold, "� Copyright Eshanatnite");

	for (int i = 0; i <= 70; i++)
	{
		fmt::print("*");
	} fmt::print("\n");

	fmt::print(fmt::emphasis::bold, "Hardware information: \n");
	fmt::print(fg(fmt::color::aquamarine) | fmt::emphasis::italic, "Number of Cores:\t{}\n", m_systemObject.m_cores);
	fmt::print(fg(fmt::color::aquamarine) | fmt::emphasis::italic, "Ram:\t{}", m_systemObject.m_ram);

	std::cout << std::flush;
}

// Todo :: incomplete
void Daletos::start(int argc, char** argv)
{
	if (argc < 2)
		fmt::print(fg(fmt::color::red) | fmt::emphasis::bold, "Insuffecient Arguments !\n Try Again");

	else
	{
		if (std::strcmp(argv[1], "-h") || std::strcmp(argv[1], "--help"))
		{
			fmt::print(fg(fmt::color::gainsboro) | fmt::emphasis::italic, "-h, --help -->\t\t");
			fmt::print(fmt::emphasis::bold, "Helps Provides documentation and help tips\n");
			fmt::print(fg(fmt::color::cyan) | fmt::emphasis::bold, "search -->\n");
			fmt::print(fg(fmt::color::alice_blue) | fmt::emphasis::bold, "search\t");
			fmt::print(fmt::emphasis::bold, "Normal Search algorithm (Set By Default)\n");
			fmt::print(fg(fmt::color::alice_blue) | fmt::emphasis::bold, "--fast-search\t");
			fmt::print(fmt::emphasis::bold, "Fast Search algorithm\n");
		}

		else if (argc > 2)  // Todo : Incomplete
		{
			if (!std::strcmp(argv[1], "search"))
			{
				// SettingUp Path variables
				if (std::string(argv[2]).rfind(".\\", 0) == 0)
				{
					m_systemObject.m_searchDir = std::string(argv[2]);
					m_file = std::string(argv[3]);
					// check fast search
					if (!std::strcmp(argv[5], "--fast_search") || !std::strcmp(argv[5], "-fs"))
					{
						collect_WIN();
					}

					collect_fs();
				}

				else
				{
					m_systemObject.m_searchDir = std::move(m_systemObject.m_cwd);
					m_file = std::string(argv[3]);
				}
			}
		}
	}
}

/* Sorts the Files Vector */
inline void Daletos::vecSort()
{
	std::sort(m_files.begin(), m_files.end());
}

/* Adds Files via the FileSystem Header */
void Daletos::collect_fs()
{
	for (const auto& entry : std::filesystem::directory_iterator(m_systemObject.m_searchDir))
	{
		m_files.emplace_back(entry.path().string());
	}

	vecSort();
}

/* Adds files using the Windows API */
void Daletos::collect_WIN()
{
	WIN32_FIND_DATA FindFileData;
	wchar_t* FileName = string2wchar_t(m_systemObject.m_searchDir);
	HANDLE hFind = FindFirstFile(FileName, &FindFileData);

	m_files.push_back(wchar_t2string(FindFileData.cFileName));

	while (FindNextFile(hFind, &FindFileData))
		m_files.push_back(wchar_t2string(FindFileData.cFileName));

	vecSort();
}

/* Find algo for the file */
void Daletos::find()
{
	std::vector<std::string>::iterator flag = std::find(m_files.begin(), m_files.end(), m_file);
	if (flag != std::end(m_files))
		fmt::print(fg(fmt::color::aquamarine), "FILE Found in the Working Directory\n");

	else
	{
		char input;
		fmt::print(fg(fmt::color::red) | fmt::emphasis::bold, "FILE not found in the Working Directory\n");
		fmt::print("Create a txt File with all the Objects in Directory? (Y/N):\t");
		std::cin >> input;

		if (input == 'Y' || input == 'y')
		{
			std::ofstream fout("Files.txt", fout.out);
			if (fout.is_open())
			{
				for (std::size_t i = 0; i < m_files.size(); i++)
				{
					if (i % 10 == 0)
						fout << std::flush;
					fout << m_files[i] << "\n";
				}

				fout.close();
				return;
			}
			else fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "file did not open");
		}
	}
}