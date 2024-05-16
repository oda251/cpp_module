#ifndef UTILS_HPP
# define UTILS_HPP
# include <iostream>
# include <limits>

bool		is_alnum(std::string str);
bool		is_valid_phonenum_char(char c);
bool		is_valid_phonenumber(std::string phonenumber);
std::string	truncate(std::string str);
void		reset_cin(void);
void		safe_cin(std::string &str);
void		safe_cin_int(int &num);

#endif