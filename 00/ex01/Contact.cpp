#include "Contact.hpp"

Contact::Contact() {};
Contact::~Contact() {};

void		Contact::displayTrunced() {
	std::ostringstream oss;
	oss << index;
	std::cout << truncate(oss.str()) << "|";
	std::cout << truncate(firstName) << "|";
	std::cout << truncate(lastName) << "|";
	std::cout << truncate(nickname) << std::endl;
}
void		Contact::display() {
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
}

void	displayHeader() {
	std::cout << truncate("index") << "|";
	std::cout << truncate("First name") << "|";
	std::cout << truncate("Last name") << "|";
	std::cout << truncate("Nickname") << std::endl;
}