#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string inputString(std::string field) {
	std::string temp;

	while (true) {
		std::cout << "Please enter " << field << std::endl;
		getline(std::cin, temp);
		if (std::cin.eof()) {
			exit(1);
		}
		if (temp != "") {
			break;
		}
	}
	return temp;
}

bool isAllDigitAndAllowedSymbol(std::string str) {
	for (int i = 0; i < (int)str.size(); i++) {
		if (!isdigit(str[i]) && str[i] != '#' && str[i] != '+' && str[i] != '*') {
			return false;
		}
	}
	return true;
}

std::string inputPhoneNumber() {
	std::string temp;

	while (true) {
		std::cout << "Please enter phonenumber (digit, *, +, #)" << std::endl;
		getline(std::cin, temp);
		if (std::cin.eof()) {
			exit(1);
		}
		if (temp != "" && isAllDigitAndAllowedSymbol(temp)) {
			break;
		}
	}
	return temp;
}

int inputDigit() {
	std::string temp;

	while (true) {
		std::cout << "Please enter index (digit)" << std::endl;
		getline(std::cin, temp);
		if (std::cin.eof()) {
			exit(1);
		}
		if ((temp.length() == 1) && ((temp[0] - '0') >= 0) && ((temp[0] - '0') <= 9)) {
			break;
		}
	}
	return temp[0] - '0';
}


void addContactToPhoneBook(PhoneBook& phoneBook) {
	Contact contact = Contact(inputString("firstname"), 
				inputString("lastName"), 
				inputString("nickName"), 
				inputPhoneNumber(), 
				inputString("darkestSecret"));
	phoneBook.addContact(contact);
}

int main() {
	PhoneBook phoneBook = PhoneBook();
	std::string cmd;

	phoneBook.init();
	while (true) {
		std::cout << "wait for command." << std::endl;
		std::cout << "ADD / SEARCH / EXIT" << std::endl;
		getline(std::cin, cmd);
		if (std::cin.eof()) {
			exit(1);
		}
		if (cmd == "ADD") {
			addContactToPhoneBook(phoneBook);
		}
		if (cmd == "SEARCH") {
			if (phoneBook.printAll()) {
				int index = inputDigit();
				Contact contact = phoneBook.findByIndex(index);
				if (contact.isEmpty()) {
					std::cout << "index error" << std::endl;
				} else {
					std::cout << "**index : " << index << std::endl;
					std::cout << "-first name : " << contact.getFirstName() << std::endl;
					std::cout << "-last name : " << contact.getLastName() << std::endl;
					std::cout << "-nickname : " << contact.getNickName() << std::endl;
					std::cout << "-phone number : " << contact.getPhoneNumber() << std::endl;
					std::cout << "-darkest secret : " << contact.getDarkestSecret() << std::endl;
				}
			}	
		}
		if (cmd == "EXIT") {
			break;
		}
	}
	return 0;
}