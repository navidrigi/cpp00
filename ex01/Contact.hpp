#pragma once

#include <iostream>
#include <iomanip>

class Contact
{
	public:
		void SetValues(std::string str1, std::string str2, std::string str3, std::string str4, std::string str5, int input);
		void PrintIndex();
		void PrintWhole();
		Contact();
		~Contact();
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		int			index;
};
