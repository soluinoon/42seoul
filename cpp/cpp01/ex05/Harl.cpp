#include "Harl.hpp"

Harl::Harl() {
	this->funcPtr[0] = &Harl::debug;
	this->funcPtr[1] = &Harl::info;
	this->funcPtr[2] = &Harl::warning;
	this->funcPtr[3] = &Harl::error;
}

void Harl::debug() {
	std::cout << "char *name : dynimic allocate" << std::endl;
}

void Harl::info() {
	std::cout << "char *name is dynamic allocated string to name jihongkim" << std::endl;
}

void Harl::warning() {
	std::cout << "reviewer said, \"i think you didn't call free\"" << std::endl;
}

void Harl::error() {
	std::cout << "retry after 3days" << std::endl;
}

void Harl::complain(std::string level) {
	std::string cmds[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++) {
		if (cmds[i] == level) {
			void (Harl::*fPtr)() = funcPtr[i];
			fptr();
		}
	}
	
}
