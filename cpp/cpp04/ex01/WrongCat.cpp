#include "WrongCat.hpp"

WrongCat::WrongCat() {
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructerd" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongCat) {
	this->type = wrongCat.type;
	std::cout << "WrongCat copy constructor" << std::endl;

}

WrongCat& WrongCat::operator=(const WrongCat& wrongCat) {
	this->type = wrongCat.type;
	std::cout << "WrongCat oper=" << std::endl;
	return (*this);
}

void WrongCat::makeSound() const {
	std::cout << "nyaong nyaong (WrongCat)" << std::endl;
}