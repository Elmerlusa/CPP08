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
	{
		Span sp = Span(10);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		Span	s(10);

		for (int i = 0; i < 10; i++)
			s.addNumber(i);
		std::cout << s.shortestSpan() << std::endl;
		std::cout << s.longestSpan() << std::endl;
	}
	{
		Span	s(100000);

		s.populate();
		std::cout << s.shortestSpan() << std::endl;
		std::cout << s.longestSpan() << std::endl;
	}
	{
		Span				s(8);
		std::list<int>		l(5, 9);
		std::vector<int>	v(2, 2);

		s.print();
		s.addNumber(l.begin(), l.end());
		s.print();
		s.addNumber(v.begin(), v.end());
		s.print();
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
