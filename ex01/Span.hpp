/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:33:45 by javmarti          #+#    #+#             */
/*   Updated: 2023/08/28 15:33:46 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

class	Span
{
	private:
		std::vector<int>	_v;
		unsigned int		_maxSize;

		Span(void);
		
		const std::vector<int>&	getV(void) const;
	public:
		Span(const Span& span);
		Span(const unsigned int& size);
		~Span(void);

		const unsigned int&		getMaxSize(void) const;

		void	populate(void);

		void	addNumber(const int& n);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

		void	print(void) const;

		Span&	operator=(const Span& span);

		template <class Iterator> void	addNumber(const Iterator& begin, const Iterator& end)
		{
			const int	insertSize = std::abs(std::distance(begin, end));

			if (this->_v.size() == this->_maxSize)
				throw Span::FullVectorException();
			if (this->_v.size() + insertSize > this->_maxSize)
				throw Span::NotEnoughSpace();
			std::copy(begin, end, std::back_inserter(this->_v));
		};

		class	NotEnoughSpace: public std::exception
		{
			virtual const char*	what(void) const throw();
		};

		class	FullVectorException: public std::exception
		{
			virtual const char*	what(void) const throw();
		};

		class	NoSpanFoundException: public std::exception
		{
			virtual const char*	what(void) const throw();
		};
};
