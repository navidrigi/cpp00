#pragma once

#include "Contact.hpp"

class PhoneBook
{
	public:
		void add();
		void search();
		void exit();
		PhoneBook();
		~PhoneBook();
	private:
		Contact contacts[8];
		int		entries;
};
