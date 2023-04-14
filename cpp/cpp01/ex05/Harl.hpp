#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <map>

class Harl {
	private:
		void debug();
		void info();
		void warning();
		void error();
		void (Harl::*funcPtr[4])();
	public:
		Harl();
		void complain(std::string level);
};

#endif