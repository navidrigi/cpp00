#include "Contact.hpp"
#include "PhoneBook.hpp"

void	Contact::SetValues(std::string str1, std::string str2, std::string str3, std::string str4, std::string str5, int input)
{
	first_name = str1;
	last_name = str2;
	nickname = str3;
	phone_number = str4;
	darkest_secret = str5;
	index = (input - 1 )% 8;
}

// used when an index is entered
void	Contact::PrintIndex()
{
	std::cout << "first name: " << first_name << std::endl;
	std::cout << "last name: " << last_name << std::endl;
	std::cout << "nickname: " << nickname << std::endl;
	std::cout << "phone number: " << phone_number << std::endl;
	std::cout << "darkest secret: " << darkest_secret << std::endl;
}

// when SEARCH command is ran
void	Contact::PrintWhole()
{
	std::cout << std::right << std::setw(10) << index;
	std::cout << "\033[32m|\033[0m";
	if (first_name.size() > 10)
		std::cout << first_name.substr(0,9) << ".";
	else
		std::cout << std::setw(10) << first_name;
	std::cout << "\033[32m|\033[0m";
	if (last_name.size() > 10)
		std::cout << last_name.substr(0,9) << ".";
	else
		std::cout << std::setw(10) << last_name;
	std::cout << "\033[32m|\033[0m";
	if (phone_number.size() > 10)
		std::cout << phone_number.substr(0,9) << ".";
	else
		std::cout << std::setw(10) << phone_number;
	std::cout << std::endl;
}

Contact::Contact()
{
}

Contact::~Contact()
{
}
