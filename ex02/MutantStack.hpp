/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:34:14 by javmarti          #+#    #+#             */
/*   Updated: 2023/08/28 17:34:14 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template<class T> class	MutantStack: public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		// const iterators since C++11

		iterator				begin(void)
		{
			return std::stack<T>::c.begin();
		}

		iterator				end(void)
		{
			return std::stack<T>::c.end();
		}

		reverse_iterator		rbegin(void)
		{
			return std::stack<T>::c.rbegin();
		}

		reverse_iterator		rend(void)
		{
			return std::stack<T>::c.rend();
		}
};
