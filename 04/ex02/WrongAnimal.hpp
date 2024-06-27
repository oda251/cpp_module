#pragma once
#include "Animal.hpp"

class WrongAnimal : public Animal
{
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& other);
		~WrongAnimal();
		WrongAnimal& operator=(const WrongAnimal& other);
};
