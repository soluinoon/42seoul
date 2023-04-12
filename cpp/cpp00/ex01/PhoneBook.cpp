#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
}

void PhoneBook::init() {
	this->size = 0;
	this->maxSize = 8;
	this->oldestIndex = 0;
}

void PhoneBook::addContact(Contact contact) {
	if (this->size == this->maxSize) {
		contacts[this->oldestIndex] = contact;
		this->oldestIndex++;
		if (this->oldestIndex == (this->maxSize - 1)) {
			this->oldestIndex = 0;
		}
		return;
	}
	contacts[this->size] = contact;
	this->size = this->size + 1;
}

int PhoneBook::printAll() {
	if (size == 0) {
		std::cout << "PhoneBook is empty" << std::endl;
		return 0;
	}
	std::cout.width(10);
	std::cout << "INDEX" << "|";
	std::cout.width(10);
	std::cout << "FIRST NAME" << "|";
	std::cout.width(10);
	std::cout << "LAST NAME" << "|";
	std::cout.width(10);
	std::cout << "NICK NAME" << std::endl;
	std::cout << "===========================================" << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout.width(10);
		std::cout << i << "|";
		std::cout.width(10);
		std::cout << subStrEndWithDot(contacts[i].getFirstName(), 10) << "|";
		std::cout.width(10);
		std::cout << subStrEndWithDot(contacts[i].getLastName(), 10) << "|";
		std::cout.width(10);
		std::cout << subStrEndWithDot(contacts[i].getNickName(), 10) << std::endl;
	}
	return 1;
}

Contact PhoneBook::findByIndex(int index) {
	if (index < 0 || index >= size) {
		Contact emptyContact;
		return emptyContact;
	}
	return contacts[index];
}

std::string PhoneBook::subStrEndWithDot(std::string str, int size) {
	std::string subStr = str.substr(0, size);

	if (str.length() > 10) {
		subStr.replace(9, 1, ".");
	}

	return subStr;
}
