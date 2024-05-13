#include <string>
#include <iostream>
#include "Harl.hpp"

void Harl::complain(std::string level)
{
	const harl_func funcs[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			std::cout << "[" << levels[i] << "]" << std::endl;
			(this->*funcs[i])();
			std::cout << std::endl;
			return ;
		}
	}
}
