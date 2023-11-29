/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:33:42 by javmarti          #+#    #+#             */
/*   Updated: 2023/08/28 15:33:43 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void): _v(std::vector<int>()), _maxSize(0)
{
}

Span::Span(const Span& span): _v(std::vector<int>(span.getV())), _maxSize(span.getMaxSize())
{
}

Span::Span(const unsigned int& size): _v(std::vector<int>()), _maxSize(size)
{
}

Span::~Span(void)
{
}

const std::vector<int>&	Span::getV(void) const
{
	return this->_v;
}

const unsigned int&	Span::getMaxSize(void) const
{
	return this->_maxSize;
}

void	Span::populate(void)
{
	if (this->_v.size() == this->_maxSize)
		return ;
	std::srand((int)time(NULL));
	for (unsigned int i = this->_v.size(); i < this->_maxSize; i++)
		this->_v.push_back(std::rand());
}

void	Span::addNumber(const int& num) 
{
	if (this->_v.size() == this->_maxSize)
		throw Span::FullVectorException();
	this->_v.push_back(num);
}

int	Span::shortestSpan(void) const
{
	std::vector<int>	vAux(this->_v.size(), 0);
	int					shortestSpan;
	
	if (this->_v.size() <= 1)
		throw Span::NoSpanFoundException();
	std::partial_sort_copy(this->_v.begin(), this->_v.end(), vAux.begin(), vAux.end());
	shortestSpan = vAux[1] - vAux[0];
	{
		int	span;

		for (std::vector<int>::const_iterator it = vAux.begin() + 1; it != vAux.end() - 1; it++)
		{
			span = *(it + 1) - *it;
			if (span < shortestSpan)
				shortestSpan = span;
			if (shortestSpan == 0)
				break ;
		}
	}
	return shortestSpan;
}

int	Span::longestSpan(void) const
{
	if (this->_v.size() <= 1)
		throw Span::NoSpanFoundException();
	return *std::max_element(this->_v.begin(), this->_v.end()) - *std::min_element(this->_v.begin(), this->_v.end());
}

void	Span::print(void) const
{
	std::cout << "Span(" << this->_maxSize << "): ";
	for (std::vector<int>::const_iterator it = this->_v.begin(); it != this->_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

Span&	Span::operator=(const Span& span)
{
	if (this != &span)
	{
		this->_maxSize = span.getMaxSize();
		this->_v = std::vector<int>(span.getV());
	}
	return *this;
}

const char*	Span::NotEnoughSpace::what(void) const throw()
{
	return "Not enough space";
}


const char*	Span::FullVectorException::what(void) const throw()
{
	return "The array is full of numbers";
}

const char*	Span::NoSpanFoundException::what(void) const throw()
{
	return "No span can be found";
}
