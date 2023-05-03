#include "Animal.hpp"

Animal::Animal() {
	this->type = "unknown";
	std::cout << "animal default constructor" << std::endl;
}

Animal::~Animal() {
	std::cout << "animal destructed" << std::endl;
}

Animal::Animal(const Animal& animal) {
	this->type = animal.type;
	std::cout << "animal copy construtor" << std::endl;
}

Animal& Animal::operator=(const Animal& animal) {
	this->type = animal.type;
	std::cout << "animal =oper" << std::endl;
	return (*this);
}

void Animal::makeSound() const {
	std::cout << "wow (animal)" << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}