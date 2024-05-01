/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:49:48 by yoda              #+#    #+#             */
/*   Updated: 2024/05/01 17:54:25 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(void) {
	Zombie* zombie1 = newZombie("Zombie1");
	Zombie* zombie2 = newZombie("Zombie2");
	randomChump("ZombieNeo");
	delete zombie1;
	delete zombie2;
	return (0);
}
