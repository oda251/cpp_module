/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:30:56 by yoda              #+#    #+#             */
/*   Updated: 2024/05/14 04:49:05 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP
# include <iostream>

bool		is_valid_phonenum_char(char c);
bool		is_valid_phonenumber(std::string phonenumber);
std::string	truncate(std::string str);

#endif