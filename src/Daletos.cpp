#include "Daletos.h"
#include "fmt/color.h"
#include "fmt/core.h"
#include <windows.h>
#include <iostream>


Daletos::Daletos()
{
	m_files.resize(10);
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
	fmt::print(fg(fmt::color::aquamarine) | fmt::emphasis::italic, "Number of Cores:\t{}\n", m_systemObject.m_ram);
	fmt::print(fg(fmt::color::aquamarine) | fmt::emphasis::italic, "Ram:\t{}", m_systemObject.m_ram);

	std::cout << std::endl;
}

// Todo :: incomplete
void Daletos::start(int argc, char** argv)
{
	if(argc < 1)
	{
		if (argv[1] == "-h" || argv[1] == "--help")
		{
			fmt::print(fg(fmt::color::gainsboro) | fmt::emphasis::italic, "-h, --help -->\t\t");
			fmt::print(fmt::emphasis::bold, "Helps Provides documentation and help tips\n");
			fmt::print(fg(fmt::color::cyan) | fmt::emphasis::bold, "search -->\n");
			fmt::print(fg(fmt::color::alice_blue) | fmt::emphasis::bold, "-s, --search\t");
			fmt::print(fmt::emphasis::bold, "Normal Search algorithm (Set By Default)\n");
			fmt::print(fg(fmt::color::alice_blue) | fmt::emphasis::bold, "-fs, --fast-search\t");
			fmt::print(fmt::emphasis::bold, "Fast Search algorithm\n");
		}

		if(argc > 2)  // Todo : Incomplete
		{
			if(argv[2] == "search")
			{}
		}
	}
}

// ?? does this even work ??
void Daletos::search_fs(const std::string& fileName)
{
	for(const auto&entry : std::filesystem::directory_iterator(m_systemObject.m_cwd))
	{
		m_files.emplace_back(entry.path().string());
	}
}