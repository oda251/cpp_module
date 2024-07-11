#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Animal& other);
		Cat(const Cat& other);
		~Cat();
		Cat& operator=(const Cat& other);

		void makeSound() const;
};
