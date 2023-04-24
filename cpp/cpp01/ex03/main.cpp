#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack(); // crude spiked club
	std::cout << "Bob attacks with their crude spiked club" << std::endl << std::endl;

	club.setType("some other type of club");
	bob.attack(); // some other type of club
	std::cout << "Bob attacks with their some other type of club" << std::endl << std::endl;
}
{
	Weapon club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	std::cout << "Jim attacks with their crude spiked club" << std::endl << std::endl;

	club.setType("some other type of club");
	jim.attack();
	std::cout << "Jim attacks with their some other type of club" << std::endl << std::endl;
}
return 0;
}