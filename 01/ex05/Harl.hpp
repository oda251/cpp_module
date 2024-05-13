#ifndef HARL_HPP
# define HARL_HPP
# include <string>
# include <iostream>
# define HARL_DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!"
# define HARL_INFO "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
# define HARL_WARNING "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
# define HARL_ERROR "This is unacceptable! I want to speak to the manager now."

class Harl {
	private:
		inline void debug(void) { std::cout << HARL_DEBUG << std::endl;}
		inline void info(void) { std::cout << HARL_INFO << std::endl;}
		inline void warning(void) { std::cout << HARL_WARNING << std::endl;}
		inline void error(void) { std::cout << HARL_ERROR << std::endl;}
	public:
		Harl(void) {};
		void complain(std::string level);
};

typedef void (Harl::*harl_func)(void);

#endif
