#include "fmt/color.h"
#include "fmt/core.h"
#include "SystemInfo.h"
#include <windows.h>
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
	sys Obj;
	fmt::print("\n**********************************************************************\n");
	fmt::print(fg(fmt::color::deep_pink) | bg(fmt::color::gainsboro) | fmt::emphasis::bold, "Daletos [Starting.....]\n");
	fmt::print("\n**********************************************************************\n");
	Sleep(700);
	system("cls");
	fmt::print("\n**********************************************************************\n");
	fmt::print(fg(fmt::color::deep_pink) | bg(fmt::color::gainsboro) | fmt::emphasis::bold, "Daletos\t");
	fmt::print(fg(fmt::color::green) | fmt::emphasis::bold, "[Status: Online]\n");
	fmt::print("Current Directory:\t {} \n", Obj.m_cwd);
	fmt::print(fmt::emphasis::bold, "� Copyright Eshanatnite");
	fmt::print("\n**********************************************************************");

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
	}

	std::cin.get();
}