#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int size;
		int maxSize;
		int oldestIndex;
		std::string subStrEndWithDot(std::string str, int size);

	public:
		PhoneBook();
		void init();
		void addContact(Contact contact);
		int printAll();
		Contact findByIndex(int index);
};

#endif