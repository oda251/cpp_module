#include "Contact.hpp"
#include "utils.hpp"

Contact::Contact() {};
Contact::~Contact() {};

void	Contact::displayTrunced() const {
	std::ostringstream oss;
	oss << _index;
	std::cout << truncate(oss.str()) << "|";
	std::cout << truncate(_firstName) << "|";
	std::cout << truncate(_lastName) << "|";
	std::cout << truncate(_nickname) << std::endl;
}
void	Contact::display() const {
	std::cout << "First name: " << _firstName << std::endl;
	std::cout << "Last name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone number: " << _phoneNumber << std::endl;
	std::cout << "Darkest secret: " << _darkestSecret << std::endl;
}

void Contact::setIndex(int index) {
	_index = index;
}
bool Contact::setFirstName(std::string firstName) {
	if (!is_alnum(firstName)) {
		return false;
	}
	_firstName = firstName;
	return true;
}
bool Contact::setLastName(std::string lastName) {
	if (!is_alnum(lastName)) {
		return false;
	}
	_lastName = lastName;
	return true;
}
bool Contact::setNickname(std::string nickname) {
	if (!is_alnum(nickname)) {
		return false;
	}
	_nickname = nickname;
	return true;
}
bool Contact::setPhoneNumber(std::string phoneNumber) {
	if (!is_valid_phonenumber(phoneNumber)) {
		return false;
	}
	_phoneNumber = phoneNumber;
	return true;
}
bool Contact::setDarkestSecret(std::string darkestSecret) {
	_darkestSecret = darkestSecret;
	return true;
}

int Contact::getIndex() const {
	return _index;
}
std::string Contact::getFirstName() const {
	return _firstName;
}
std::string Contact::getLastName() const {
	return _lastName;
}
std::string Contact::getNickname() const {
	return _nickname;
}
std::string Contact::getPhoneNumber() const {
	return _phoneNumber;
}
std::string Contact::getDarkestSecret() const {
	return _darkestSecret;
}

void	displayContactHeader() {
	std::cout << truncate("index") << "|";
	std::cout << truncate("First name") << "|";
	std::cout << truncate("Last name") << "|";
	std::cout << truncate("Nickname") << std::endl;
}

Contact &Contact::operator=(const Contact &rhs) {
	_index = rhs.getIndex();
	_firstName = rhs.getFirstName();
	_lastName = rhs.getLastName();
	_nickname = rhs.getNickname();
	_phoneNumber = rhs.getPhoneNumber();
	_darkestSecret = rhs.getDarkestSecret();
	return *this;
}
