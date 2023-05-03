#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(int count) {
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog " << count << std::endl;
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog destructerd" << std::endl;
}

Dog::Dog(const Dog& dog) {
	this->type = dog.type;
	this->brain = dog.brain;
	std::cout << "Dog copy constructor" << std::endl;

}

Dog& Dog::operator=(const Dog& dog) {
	this->type = dog.type;
	this->brain = dog.brain;
	std::cout << "Dog oper=" << std::endl;
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "meong meong (dog)" << std::endl;
}