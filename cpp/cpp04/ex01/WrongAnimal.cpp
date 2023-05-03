#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	this->type = "unknown";
	std::cout << "WrongAnimal default constructor" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wrongAnimal) {
	this->type = wrongAnimal.type;
	std::cout << "WrongAnimal copy construtor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wrongAnimal) {
	this->type = wrongAnimal.type;
	std::cout << "WrongAnimal =oper" << std::endl;
	return (*this);
}

void WrongAnimal::makeSound() const {
	std::cout << "euk (WrongAnimal)" << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->type;
}