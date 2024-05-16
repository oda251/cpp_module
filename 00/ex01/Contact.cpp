#include "Contact.hpp"

Contact::Contact() {};
Contact::~Contact() {};

void	Contact::displayTrunced() {
	std::ostringstream oss;
	oss << _index;
	std::cout << truncate(oss.str()) << "|";
	std::cout << truncate(_firstName) << "|";
	std::cout << truncate(_lastName) << "|";
	std::cout << truncate(_nickname) << std::endl;
}
void	Contact::display() {
	std::cout << "First name: " << _firstName << std::endl;
	std::cout << "Last name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone number: " << _phoneNumber << std::endl;
	std::cout << "Darkest secret: " << _darkestSecret << std::endl;
}

void	displayHeader() {
	std::cout << truncate("index") << "|";
	std::cout << truncate("First name") << "|";
	std::cout << truncate("Last name") << "|";
	std::cout << truncate("Nickname") << std::endl;
}