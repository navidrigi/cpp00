#pragma once

#include "Contact.hpp"

class PhoneBook
{
	public:
		void add();
		void search();
		PhoneBook();
		~PhoneBook();
	private:
		Contact contacts[8];
		int		entries;
};
