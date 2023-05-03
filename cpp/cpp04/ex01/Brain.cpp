#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; i++) {
		ideas[i] = "something";
	}
}

Brain::~Brain() {
	std::cout << "Brain destructed" << std::endl;
}

Brain::Brain(const Brain& brain) {
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = brain.ideas[i];
	}
	std::cout << "Brain copy construtor" << std::endl;
}

Brain& Brain::operator=(const Brain& brain) {
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = brain.ideas[i];
	}
	std::cout << "Brain =oper" << std::endl;
	return (*this);
}