/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:33:38 by javmarti          #+#    #+#             */
/*   Updated: 2023/08/28 15:33:39 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Span.hpp"

#include <list>

int	main(void)
{
	{
		Span	s(50000);

		try
		{
			for (unsigned int i = 0; i < s.getMaxSize() + 1; i++)
				s.addNumber(i);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "-------------------------------------------------------------------------------" << std::endl;
	{
		Span	s(0);

		try
		{
			std::cout << s.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		
	}
	std::cout << "-------------------------------------------------------------------------------" << std::endl;
	{
		Span s = Span(10);

		s.addNumber(6);
		s.addNumber(3);
		s.addNumber(17);
		s.addNumber(9);
		s.addNumber(11);
		std::cout << "Shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "Longest span: " << s.longestSpan() << std::endl;
	}
	std::cout << "-------------------------------------------------------------------------------" << std::endl;
	{
		Span	s(10);

		for (unsigned int i = 0; i < s.getMaxSize(); i++)
			s.addNumber(i);
		std::cout << "Shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "Longest span: " << s.longestSpan() << std::endl;
	}
	std::cout << "-------------------------------------------------------------------------------" << std::endl;
	{
		Span	s(100000);

		s.populate();
		std::cout << "Shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "Longest span: " << s.longestSpan() << std::endl;
	}
	std::cout << "-------------------------------------------------------------------------------" << std::endl;
	{
		Span				s(8);
		std::list<int>		l(5, 9);
		std::vector<int>	v(2, 2);

		s.print();
		s.addNumber(l.begin(), l.end());
		s.print();
		s.addNumber(v.begin(), v.end());
		s.print();
		std::cout << "Shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "Longest span: " << s.longestSpan() << std::endl;
		try
		{
			s.addNumber(l.begin(), l.end());
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
