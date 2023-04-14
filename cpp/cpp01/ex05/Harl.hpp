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
		void (*funcPtr[4])();
		std::map<std::string, void (Harl::*)()> funcMap;
	public:
		Harl();
		void complain(std::string level);
};

#endif