#pragma once

class AbstractAnimal {
	protected:
		std::string _type;
	public:
		AbstractAnimal(void);
		AbstractAnimal(std::string type);
		AbstractAnimal(const AbstractAnimal& other);
		virtual ~AbstractAnimal();
		AbstractAnimal& operator=(const AbstractAnimal& other);

		std::string getType() const;
		void setType(const std::string& type);

		virtual void makeSound() const = 0;
};
