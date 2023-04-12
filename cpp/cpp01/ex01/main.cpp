#include "Zombie.hpp"

int main() {
	Zombie *jihongHorde = zombieHorde(10, "jihong");

	for (int i = 0; i < 10; i++) {
			std::cout << i << " jihong announce!!!" << std::endl;
			jihongHorde[i].announce();
	}
	delete[] jihongHorde;
}