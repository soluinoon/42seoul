#include "Zombie.hpp"
#include <stdlib.h>

int main() {
	Zombie *jihongKim = newZombie("jihongKim");
	jihongKim->announce();
	delete jihongKim;

	randomChump("short");
}