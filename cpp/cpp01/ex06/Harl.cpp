#include "Harl.hpp"

Harl::Harl() {
}

void Harl::debug() {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "char *name : dynimic allocate" << std::endl;
}

void Harl::info() {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "\"char *name\" is dynamic allocated string to name jihongkim" << std::endl;
}

void Harl::warning() {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "reviewer said, \"i think you didn't call free\"" << std::endl;
}

void Harl::error() {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "retry after 3days" << std::endl;
}

void Harl::complain(std::string level) {
	void (Harl::*fPtr)(void) = nullptr;
	std::string cmds[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int cmdIndex = -1;

	for (int i = 0; i < 4; i++) {
		if (cmds[i] == level) {
			cmdIndex = i;
		}
	}

	switch (cmdIndex) {
		case 0:
			fPtr = &Harl::debug;
			break;
		case 1:
			fPtr = &Harl::info;
			break;
		case 2:
			fPtr = &Harl::warning;
			break;
		case 3:
			fPtr = &Harl::error;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			return;
	}
	(this->*fPtr)();

}
