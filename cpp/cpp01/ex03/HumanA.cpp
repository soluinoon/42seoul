#include "HumanA.hpp"

HumanA::HumanA(Weapon weapon, std::string name) : weapon(weapon){
	this->name = name;
}

void HumanA::attack() {
	std::cout << this->name << "attacks with their" << this->weapon.getType() << std::endl;
}