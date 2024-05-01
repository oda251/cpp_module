/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:49:48 by yoda              #+#    #+#             */
/*   Updated: 2024/05/01 19:03:16 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

__attribute__((destructor))
void    destructor(void)
{
    int     status;
    char    buf[50];

    snprintf(buf, 50, "leaks %d &> leaksout", getpid());
    status = system(buf);
    if (status)
    {
        write(2, "leak!!!\n", 8);
        system("cat leaksout >/dev/stderr");
        exit(1);
    }
}

int main(void) {
	Zombie* horde = zombieHorde(5, "Zombie");
	for (int i = 0; i < 5; i++) {
		horde[i].announce();
	}
}
