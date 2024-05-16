/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:49:48 by yoda              #+#    #+#             */
/*   Updated: 2024/05/17 00:22:20 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);
void	deleteZombieHorde(Zombie *zombies);

__attribute__((destructor))
void    destructor(void)
{
	#ifdef LEAKS
	std::cout << "--- Destructor ---" << std::endl;
	system(LEAKS);
	#endif
}

int main(void) {
	std::cout << "--- Test 1 ---" << std::endl;
	Zombie* horde = zombieHorde(0, "TeamZombie");
	std::cout << horde << std::endl;
	std::cout << "--- Test 2 ---" << std::endl;
	horde = zombieHorde(-1, "TeamZombie");
	std::cout << horde << std::endl;
	std::cout << "--- Test 3 ---" << std::endl;
	horde = zombieHorde(5, "TeamZombie");
	for (int i = 0; i < 5; i++) {
		std::cout << "[Zombie " << i << "]" << std::endl;
		horde[i].announce();
	}
	deleteZombieHorde(horde);
}
