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

#include <deque>

template<class T> class	MutantStack: public std::deque
{
	public:
		T&	top(void) const
		{
			return this->back();
		}

		void	push(T& t)
		{
			this->push_back(t);
		}

		void	emplace(T t)
		{
			this->emplace_back(t);
		}

		void	pop(void);
		{
			this->pop_back();
		}

		void	swap(MutantStack& mutantStack)
		{
			this->swap(mutantStack);
		}
};
