#include "fmt/color.h"
#include "fmt/core.h"
#include "SystemInfo.h"

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
	fmt::print("Current Directory:\t {} \n", Obj.returnCWD());
	fmt::print(fmt::emphasis::bold, "© Copyright Eshanatnite");
	fmt::print("\n**********************************************************************");
	std::cin.get();
}