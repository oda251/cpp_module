#include "AMateria.hpp"
#include "MateriaSource.hpp"

// class MateriaSource : public IMateriaSource
// {
// 	private:
// 		AMateria *memories[4];
// 	public:
// 		MateriaSource(void);
// 		MateriaSource(MateriaSource const & src);
// 		MateriaSource & operator=(MateriaSource const & src);
// 		~MateriaSource();
// 		void learnMateria(AMateria* m);
// 		AMateria* createMateria(std::string const & type);
// };

MateriaSource::MateriaSource(void) {
	for (int i = 0; i < 4; i++)
		memories[i] = NULL;
}
MateriaSource::MateriaSource(MateriaSource const & src) {
	*this = src;
}
MateriaSource & MateriaSource::operator=(MateriaSource const & src) {
	if (this != &src) {
		for (int i = 0; i < 4; i++) {
			if (src.memories[i]) {
				memories[i] = src.memories[i]->clone();
			}
			else
				memories[i] = NULL;
		}
	}
	return *this;
}
MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (memories[i])
			delete memories[i];
	}
}
void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!memories[i]) {
			memories[i] = m->clone();
			break;
		}
	}
}
AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (memories[i] && memories[i]->getType() == type)
			return memories[i]->clone();
	}
	return NULL;
}
