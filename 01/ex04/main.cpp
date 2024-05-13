/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:49:48 by yoda              #+#    #+#             */
/*   Updated: 2024/05/14 04:07:29 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

bool fileExists(const std::string &fileName)
{
	std::ifstream file(fileName.c_str());
	if (file)
	{
		file.close();
		return true;
	}
	return false;
}

int main(int argc, char **argv) {
	if (argc != 4)
	{
		std::cerr << "Error: invalid arguments\n";
		std::cerr << "usage: ./sed filename s1 s2" << std::endl;
		return EXIT_FAILURE;
	}
	std::string fileName = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream infile(fileName.c_str());
	if (!infile)
	{
		std::cerr << "Error: failed to open file" << std::endl;
		return EXIT_FAILURE;
	}
	if (fileExists(fileName + ".replace"))
	{
		std::cerr << "Error: file already exists" << std::endl;
		return EXIT_FAILURE;
	}
	std::ofstream outfile((fileName + ".replace"));
	if (!outfile)
	{
		std::cerr << "Error: failed to create file" << std::endl;
		return EXIT_FAILURE;
	}

	std::string line;
	while (std::getline(infile, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outfile << line << std::endl;
	}
	infile.close();
	outfile.close();
	return EXIT_SUCCESS;
}
