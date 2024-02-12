#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	entries = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::add()
{
	std::string entry[5];

	// std::cout << "\033[96mfirst name: \033[0m";
	// std::cin >> entry[0];
	// std::getline(std::cin, entry[0]);
	do {
		std::cout << "\033[96mfirst name: \033[0m";
		std::getline(std::cin, entry[0]);
	} while (entry[0].empty());
	do {
		std::cout << "\033[96mlast name: \033[0m";
		std::getline(std::cin, entry[1]);
	} while (entry[0].empty());
	do {
		std::cout << "\033[96mnickname: \033[0m";
		std::getline(std::cin, entry[2]);
	} while (entry[0].empty());
	do {
		std::cout << "\033[96mphone number: \033[0m";
		std::getline(std::cin, entry[3]);
	} while (entry[0].empty());
	do {
		std::cout << "\033[96mdarkest secret: \033[0m";
		std::getline(std::cin, entry[4]);
	} while (entry[0].empty());
	// std::cout << "\033[96mlast name: \033[0m";
	// // std::cin >> entry[1];
	// std::getline(std::cin, entry[1]);
	// std::cout << "\033[96mnickname: \033[0m";
	// // std::cin >> entry[2];
	// std::getline(std::cin, entry[2]);
	// std::cout << "\033[96mphone number: \033[0m";
	// // std::cin >> entry[3];
	// std::getline(std::cin, entry[3]);
	// std::cout << "\033[96mdarkest secret: \033[0m";
	// // std::cin >> entry[4];
	// std::getline(std::cin, entry[4]);
	entries++;
	contacts[(entries - 1) % 8].SetValues(entry[0], entry[1], entry[2], entry[3], entry[4], entries);
}

void	PhoneBook::search()
{
	int j = 0;
	int index;

	std::cout << std::left << std::setw(10) << "Index";
	std::cout << "\033[32m|\033[0m";
	std::cout << std::left << std::setw(10) << "FirstName";
	std::cout << "\033[32m|\033[0m";
	std::cout << std::left << std::setw(10) << "LastName";
	std::cout << "\033[32m|\033[0m";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	while (j < entries && j < 8)
	{
		contacts[j].PrintWhole();
		j++;
	}
	std::cout << "\033[93mEnter an Index: \033[0m";
	std::cin >> index;
	if (index < 0 || index > 7)
		std::cout << "\033[31m*** Index must be between 0 and 7 ***\033[0m" << std::endl;
	else if (index > entries)
		std::cout << "\033[34m*** Still no entry for this Index ***\033[0m" << std::endl;
	else
		contacts[index % 8].PrintIndex();
}