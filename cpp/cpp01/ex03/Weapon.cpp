#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	std::cout << "call type param construct" << std::endl;
	this->type = type;
}

const std::string &Weapon::getType() {
	return this->type;
}

void Weapon::setType(std::string type) {
	this->type = type;
}