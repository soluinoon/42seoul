#include "Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(int count) {
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat 1" << count << std::endl;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructerd" << std::endl;
}

Cat::Cat(const Cat& cat) {
	this->type = cat.type;
	this->brain = cat.brain;
	std::cout << "Cat copy constructor" << std::endl;

}

Cat& Cat::operator=(const Cat& cat) {
	this->type = cat.type;
	this->brain = cat.brain;
	std::cout << "Cat oper=" << std::endl;
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "nyaong nyaong (cat)" << std::endl;
}