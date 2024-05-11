/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:49:48 by yoda              #+#    #+#             */
/*   Updated: 2024/05/11 16:52:28 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);
void	deleteZombieHorde(Zombie *zombies);

__attribute__((destructor))
void    destructor(void)
{
	std::cout << "--- Destructor ---" << std::endl;
	system("leaks -q zombie");
}

int main(void) {
	Zombie* horde = zombieHorde(5, "Zombie");
	for (int i = 0; i < 5; i++) {
		horde[i].announce();
	}
	deleteZombieHorde(horde);
}
