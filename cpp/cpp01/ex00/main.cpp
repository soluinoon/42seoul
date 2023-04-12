#include "Zombie.hpp"

int main() {
	
	Zombie *jihongKim = newZombie("jihongKim");
	jihongKim->announce();
	randomChump("short");
	delete jihongKim;
}