/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:30:44 by yoda              #+#    #+#             */
/*   Updated: 2024/05/01 17:33:19 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Zombie {
	private:
		std::string _name;

	public:
		Zombie(void);
		Zombie(std::string name);
		void setName(std::string name);
		std::string getName(void);
		void announce(void);
};
