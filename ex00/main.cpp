/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:33:33 by javmarti          #+#    #+#             */
/*   Updated: 2023/08/28 15:33:34 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <queue>

#include "easyfind.hpp"

int	main(void)
{
	std::cout << "---Vector---\n";
	{
		std::vector<int>	v(3, 5);

		try
		{
			std::cout << "Found: " << easyfind(v, 5) << std::endl;
			std::cout << "Found: " << easyfind(v, 1) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "---Deque---\n";
	{
		int				myInts[] = {-4, 7, 8 ,9};
		std::deque<int>	d(myInts, myInts + sizeof(myInts) / sizeof(int));

		try
		{
			std::cout << "Found: " << easyfind(d, -4) << std::endl;
			std::cout << "Found: " << easyfind(d, 9) << std::endl;
			std::cout << "Found: " << easyfind(d, 0) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "---List---\n";
	{
		int				myInts[] = {-3, 0, -9, 8, 8};
		std::list<int>	l(myInts, myInts + sizeof(myInts) / sizeof(int));

		try
		{
			std::cout << "Found: " << easyfind(l, -9) << std::endl;
			std::cout << "Found: " << easyfind(l, 0) << std::endl;
			std::cout << "Found: " << easyfind(l, 8) << std::endl;
			std::cout << "Found: " << easyfind(l, 3) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
