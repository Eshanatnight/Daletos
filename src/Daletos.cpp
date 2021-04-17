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

Daletos::Daletos()
{
	m_argv.reserve(2);
	m_files.reserve(10);

	/*
	//	Arg Analysis
	// might use as app arguments
	// or
	// a different function
	*/
	fmt::print(fg(fmt::color::deep_pink), "Please input Parameters\n");
	fmt::print(fg(fmt::color::deep_pink), "for help write \"--help\" or \"-h\"\n");
	fmt::print("First Argument \"path\"\nSecond Argumrnt \"file name\"\nthird Argument (optional) keyword \"--fast-search\" or \"-fs\"\n");
	char input[256];
	for (int i = 0; i < 3; i++)
	{
		std::cin.getline(input, 255);
		m_argv.emplace_back(input);
	}
}

/* For Screen initialization */
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
	fmt::print("Current Directory:\t {} \n", m_systemObject.m_cwd);
	fmt::print(fmt::emphasis::bold, "� Copyright Eshanatnite");

	for (int i = 0; i <= 70; i++)
	{
		fmt::print("*");
	} fmt::print("\n");

	fmt::print(fmt::emphasis::bold, "Hardware information: \n");
	fmt::print(fg(fmt::color::aquamarine) | fmt::emphasis::italic, "Number of Cores:\t{}\n", m_systemObject.m_cores);
	fmt::print(fg(fmt::color::aquamarine) | fmt::emphasis::italic, "Ram:\t{}", m_systemObject.m_ram + 1);

	std::cout << std::flush;
}

/* For handleing parameters passed */
void Daletos::paremHandling()
{
	// insuffecient arguments passed or help is called
	if (m_argv[0].empty() || m_argv[1].empty() || (m_argv[0] == "-h" || m_argv[0] == "--help"))
	{
		fmt::print(fg(fmt::color::red) | fmt::emphasis::bold, "Insuffecient or Incorrect Arguments !\n Try Again");
		appHelp();
	}

	else
	{
		// if relative path is given as the current Directory
		if (m_argv[0].rfind(".\\", 0) == 0)
		{
			m_systemObject.m_searchDir = std::move(m_systemObject.m_cwd);
			m_fileName = std::move(m_argv[1]);
		}
		// if absolute path is given a
		else
		{
			m_systemObject.m_searchDir = std::move(m_argv[0]);
			m_fileName = std::move(m_argv[1]);
		}

		if (m_argv[2] == "")
			collect_fs();

		else if (m_argv[2] == "--fast_search" || m_argv[2] == "-fs")
			collect_WIN();

		else
			fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "Incorrect Parrameters Passed\nExeption Thrown\n");
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
		m_files.emplace_back(entry.path().string().erase(0, m_systemObject.m_searchDir.length() + 1));

	vecSort();
}

/* Adds files using the Windows API */
void Daletos::collect_WIN()
{
	WIN32_FIND_DATA FindFileData;
	wchar_t* FileName = string2wchar_t(m_systemObject.m_searchDir);
	HANDLE hFind = FindFirstFile(FileName, &FindFileData);

	m_files.push_back(std::move(wchar_t2string(FindFileData.cFileName)));

	while (FindNextFile(hFind, &FindFileData))
		m_files.push_back(std::move(wchar_t2string(FindFileData.cFileName)));

	vecSort();
}

/* Finds the file */
void Daletos::FindAndList()
{
	std::vector<std::string>::iterator flag = std::find(m_files.begin(), m_files.end(), m_fileName);
	if (flag != std::end(m_files))
		fmt::print(fg(fmt::color::aquamarine), "FILE Found in the Working Directory\n");

	else
		fmt::print(fg(fmt::color::red) | fmt::emphasis::bold, "FILE not found in the Working Directory\n");

	char input;
	fmt::print("Create a txt File with all the Objects in Directory? (Y/N):\t");
	std::cin >> input;

	if (input == 'Y' || input == 'y')
	{
		std::ofstream fout("Files.txt", std::ios::out);
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

		else
			fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "file did not open");
	}
}

/*
/* Definition Search * / // maybe deleted
void Daletos::helpSearch()
{
	fmt::print(fg(fmt::color::cyan) | fmt::emphasis::bold, "search -->\n");
	fmt::print(fg(fmt::color::alice_blue) | fmt::emphasis::bold, "search\t");
	fmt::print(fmt::emphasis::bold, "Normal Search algorithm (set by default)\n");
	fmt::print(fg(fmt::color::alice_blue) | fmt::emphasis::bold, "--fast-search, -fs\t");
	fmt::print(fmt::emphasis::bold, "Fast Search algorithm\n");
	fmt::print(fg(fmt::color::gainsboro), "pass the path as the second argument\n");
}
*/
/* App help */
void Daletos::appHelp()
{
	fmt::print(fg(fmt::color::gainsboro) | fmt::emphasis::italic, "-h, --help -->\t\t");
	fmt::print(fmt::emphasis::bold, "Helps Provides documentation and help tips\n");
	fmt::print(fg(fmt::color::cyan) | fmt::emphasis::bold, "search -->\n");
	fmt::print(fg(fmt::color::alice_blue) | fmt::emphasis::bold, "search\t");
	fmt::print(fmt::emphasis::bold, "Normal Search algorithm (set by default)\n");
	fmt::print(fg(fmt::color::alice_blue) | fmt::emphasis::bold, "--fast-search\t");
	fmt::print(fmt::emphasis::bold, "Fast Search algorithm\n");
}

/* Starts the app */
void Daletos::start()
{
	ScreenInit();
	paremHandling();
	FindAndList();
}