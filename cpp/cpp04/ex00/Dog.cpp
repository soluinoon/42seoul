#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	std::cout << "Dog default constructor" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructerd" << std::endl;
}

Dog::Dog(const Dog& Dog) {
	this->type = Dog.type;
	std::cout << "Dog copy constructor" << std::endl;

}

Dog& Dog::operator=(const Dog& Dog) {
	this->type = Dog.type;
	std::cout << "Dog oper=" << std::endl;
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "meong meong (dog)" << std::endl;
}