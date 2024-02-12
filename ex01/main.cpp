#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	PhoneBook	phonebook;
	std::string	str;

	while (true)
	{
		std::cout << "\033[35mEnter the Command: \033[0m";
		// cin >> for single characters
		// getline -> line inputs
		std::getline(std::cin, str);
		if (str.empty())
			continue;
		// if (std::cin.eof() || std::cin.fail())
		if (std::cin.eof())
		{
			std::cout << "EOF" << std::endl;
			return (0);
		}
		if (str == "ADD")
			phonebook.add();

		else if (str == "SEARCH")
			phonebook.search();

		else if (str == "EXIT")
			return 0;
	}
}
