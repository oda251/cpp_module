/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:49:50 by yoda              #+#    #+#             */
/*   Updated: 2024/05/01 17:33:14 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {
	_name = "zombie";
}
Zombie::Zombie(std::string name) {
	_name = name;
}
void Zombie::setName(std::string name) {
	_name = name;
}
std::string Zombie::getName(void) {
	return (_name);
}
void Zombie::announce(void) {
	std::cout << "<" << _name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}
