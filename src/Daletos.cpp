#include "Daletos.h"
#include "fmt/color.h"
#include "fmt/core.h"
#include <windows.h>
#include <iostream>

Daletos::Daletos()
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
	fmt::print(fmt::emphasis::bold, "© Copyright Eshanatnite");

	for (int i = 0; i <= 70; i++)
	{
		fmt::print("*");
	} fmt::print("\n");

	fmt::print(fmt::emphasis::bold, "Hardware information: \n");
	fmt::print(fg(fmt::color::aquamarine) | fmt::emphasis::italic, "Number of Cores:\t{}\n", m_systemObject.m_ram);
	fmt::print(fg(fmt::color::aquamarine) | fmt::emphasis::italic, "Ram:\t{}", m_systemObject.m_ram);

	std::cout << std::endl;
}