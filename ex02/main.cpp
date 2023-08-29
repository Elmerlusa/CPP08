/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:38:23 by javmarti          #+#    #+#             */
/*   Updated: 2023/08/28 15:38:23 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>

#include "MutantStack.hpp"

int	main(void)
{
	std::cout << "---List---" << std::endl;
	{
		std::list<int>	l;
		l.push_back(5);
		l.push_back(17);
		std::cout << l.back() << std::endl;
		l.pop_back();
		std::cout << "size -> " << l.size() << std::endl;
		l.push_back(3);
		l.push_back(5);
		l.push_back(737);
		l.push_back(0);
		std::list<int>::iterator it = l.begin();
		std::list<int>::iterator ite = l.end();
		++it;
		*it = 999;
		--it;
		std::cout << "FORWARD: " << l.size() << std::endl;
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
		std::stack<int, std::list<int> > s(l);
		l.push_back(3);
		l.push_back(5);
		l.push_back(737);
		std::cout << "REVERSE: " << l.size() << std::endl;
		std::list<int>::reverse_iterator	rIt = l.rbegin();
		std::list<int>::reverse_iterator	rIte = l.rend();
		++rIt;
		*rIt = 1;
		--rIt;
		while (rIt != rIte)
		{
			std::cout << *rIt << " ";
			++rIt;
		}
		std::cout << std::endl;
	}
	std::cout << "---MutantStack---" << std::endl;
	{
		MutantStack<int> mstack;
		std::cout << "Empty -> " << mstack.empty() << std::endl;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size -> " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		*it = 999;
		--it;
		std::cout << "FORWARD: " << mstack.size() << std::endl;
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
		std::stack<int> s(mstack);
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		std::cout << "REVERSE: " << mstack.size() << std::endl;
		MutantStack<int>::reverse_iterator	rIt = mstack.rbegin();
		MutantStack<int>::reverse_iterator	rIte = mstack.rend();
		++rIt;
		*rIt = 1;
		--rIt;
		while (rIt != rIte)
		{
			std::cout << *rIt << " ";
			++rIt;
		}
		std::cout << std::endl;
	}
	return 0;
}