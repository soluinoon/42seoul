#include "Harl.hpp"

Harl::Harl() {
	this->funcPtr[0] = this->debug();
	this->funcPtr[1] = Harl::info;
	this->funcPtr[2] = Harl::warning;
	this->funcPtr[3] = Harl::error;

	this->funcMap.insert(std::pair<std::string, void (Harl::*)()>("DEBUG", funcPtr[0]));
	this->funcMap.insert(std::pair<std::string, void (Harl::*)()>("INFO", funcPtr[1]));
	this->funcMap.insert(std::pair<std::string, void (Harl::*)()>("WARNING", funcPtr[2]));
	this->funcMap.insert(std::pair<std::string, void (Harl::*)()>("ERROR", funcPtr[3]));
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
	void (Harl::*levelPtr)() = funcMap.at(level);
	levelPtr();
}
