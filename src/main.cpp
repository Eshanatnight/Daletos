#include "fmt/color.h"
#include "fmt/core.h"
#include "fmt/color.h"
#include <iostream>
#include "SystemInfo.h"

int main(int argc, char** argv)
{
	fmt::print(fg(fmt::color::deep_pink) | fmt::emphasis::bold, "Daletos [Starting.....]\n");
	system("cls");
	fmt::print(fg(fmt::color::deep_pink) | bg(fmt::color::gainsboro) | fmt::emphasis::bold, "Daletos");
	fmt::print(fg(fmt::color::green) | fmt::emphasis::bold, "[Status: Online]\n");

	std::string m_cwd = get_current_dir();
	fmt::print("Current Directory:\t {} \n", get_current_dir());
	std::cin.get();
}