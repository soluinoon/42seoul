#include "Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
	std::cout << "Cat default constructor" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructerd" << std::endl;
}

Cat::Cat(const Cat& cat) {
	this->type = cat.type;
	std::cout << "Cat copy constructor" << std::endl;

}

Cat& Cat::operator=(const Cat& cat) {
	this->type = cat.type;
	std::cout << "Cat oper=" << std::endl;
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "nyaong nyaong (cat)" << std::endl;
}