/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:24:49 by corellan          #+#    #+#             */
/*   Updated: 2023/10/30 09:32:23 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
extern "C"
{
	#define new testi
	#include "libft.h"
	#undef testi
}

int	main(void)
{
	int			n_atoi;
	int 		n_ft_atoi;
	std::string	number;

	number.clear();
	std::cout << "TESTING POSITIVE NUMBERS" << std::endl;
	for (size_t i = 0; i < 200; i++)
	{
		if (!i)
			number.append("+1");
		else
			number.push_back('0');
		n_atoi = atoi(number.data());
		n_ft_atoi = ft_atoi(number.data());
		std::cout << "cycle " << i << ": result atoi: " << n_atoi << ", result ft_atoi: " << n_ft_atoi << ". ";
		if (n_atoi == n_ft_atoi)
			std::cout << "\033[0;32m" << "OK";
		else
			std::cout << "\033[0;31m" << "KO";
		std::cout << "\033[0m" << "." << std::endl;
		usleep(50000);
	}
	number.clear();
	std::cout << "TESTING NEGATIVE NUMBERS" << std::endl;
	for (size_t i = 0; i < 200; i++)
	{
		if (!i)
			number.append("-1");
		else
			number.push_back('0');
		n_atoi = atoi(number.data());
		n_ft_atoi = ft_atoi(number.data());
		std::cout << "cycle " << i << ": result atoi: " << n_atoi << ", result ft_atoi: " << n_ft_atoi << ". ";
		if (n_atoi == n_ft_atoi)
			std::cout << "\033[0;32m" << "OK";
		else
			std::cout << "\033[0;31m" << "KO";
		std::cout << "\033[0m" << "." << std::endl;
		usleep(50000);
	}
	number.clear();
	std::cout << "Testing not well written numbers" << std::endl;
	number.append("+ 10");
	n_atoi = atoi(number.data());
	n_ft_atoi = ft_atoi(number.data());
	std::cout << "cycle " << 0 << ": result atoi: " << n_atoi << ", result ft_atoi: " << n_ft_atoi << ". ";
	if (n_atoi == n_ft_atoi)
		std::cout << "\033[0;32m" << "OK";
	else
		std::cout << "\033[0;31m" << "KO";
	std::cout << "\033[0m" << "." << std::endl;
	usleep(50000);
	number.clear();
	number.append("+1 0");
	n_atoi = atoi(number.data());
	n_ft_atoi = ft_atoi(number.data());
	std::cout << "cycle " << 1 << ": result atoi: " << n_atoi << ", result ft_atoi: " << n_ft_atoi << ". ";
	if (n_atoi == n_ft_atoi)
		std::cout << "\033[0;32m" << "OK";
	else
		std::cout << "\033[0;31m" << "KO";
	std::cout << "\033[0m" << "." << std::endl;
	usleep(50000);
	number.clear();
	number.append(" +1a0");
	n_atoi = atoi(number.data());
	n_ft_atoi = ft_atoi(number.data());
	std::cout << "cycle " << 2 << ": result atoi: " << n_atoi << ", result ft_atoi: " << n_ft_atoi << ". ";
	if (n_atoi == n_ft_atoi)
		std::cout << "\033[0;32m" << "OK";
	else
		std::cout << "\033[0;31m" << "KO";
	std::cout << "\033[0m" << "." << std::endl;
	usleep(50000);
	return (0);
}
