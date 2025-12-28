#pragma once
#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *memories[4];
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & src);
		MateriaSource & operator=(MateriaSource const & src);
		~MateriaSource();
		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};
