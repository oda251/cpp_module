#pragma once

class Animal {
	protected:
		std::string _type;
	public:
		Animal(void);
		Animal(std::string type);
		Animal(const Animal& other);
		virtual ~Animal();
		Animal& operator=(const Animal& other);

		std::string getType() const;
		void setType(const std::string& type);

		virtual void makeSound() const = 0;
};
