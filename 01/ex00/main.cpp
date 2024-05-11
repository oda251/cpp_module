/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:49:48 by yoda              #+#    #+#             */
/*   Updated: 2024/05/11 16:53:01 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

__attribute__((destructor))
void destructor(void)
{
	std::cout << "--- Destructor ---" << std::endl;
	system("leaks -q zombie");
}

int main(void) {
	Zombie* zombie1 = newZombie("Zombie1");
	Zombie* zombie2 = newZombie("Zombie2");
	randomChump("ZombieNeo");
	delete zombie1;
	delete zombie2;
	return (0);
}
