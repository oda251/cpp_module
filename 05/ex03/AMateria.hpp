#pragma once
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & src);
		AMateria & operator=(AMateria const & src);
		virtual ~AMateria() = 0;
		virtual std::string const & getType() const = 0;
		virtual void setType(std::string const &type) = 0;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) = 0;
};
