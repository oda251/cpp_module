/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:39:35 by yoda              #+#    #+#             */
/*   Updated: 2024/05/14 04:19:15 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

bool	is_valid_phonenum_char(char c) {
	return std::isdigit(c) || c == '-' || c == '+' || c == '(' || c == ')';
}

bool	is_valid_phonenumber(std::string phonenumber) {
	for (size_t i = 0; i < phonenumber.length(); i++) {
		if (!is_valid_phonenum_char(phonenumber[i])) {
			return false;
		}
	}
	return true;
}

std::string	truncate(std::string str) {
	if (str.length() > 10) {
		str.resize(9);
		str.append(".");
	} else if (str.length() < 10) {
		str.insert(0, 10 - str.length(), ' ');
	}
	return str;
}
