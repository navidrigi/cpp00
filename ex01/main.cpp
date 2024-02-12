#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	PhoneBook	phonebook;
	std::string	str;

	while (true)
	{
		std::cout << "\033[35mEnter the Command: \033[0m";
		std::getline(std::cin, str);
		if (std::cin.eof())
		{
			std::cout << "EOF" << std::endl;
			return (0);
		}
		if (str.empty())
			continue;
		if (str == "ADD")
			phonebook.add();

		else if (str == "SEARCH")
			phonebook.search();

		else if (str == "EXIT")
			return 0;
	}
}
