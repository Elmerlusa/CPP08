#pragma once

#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

class	Span
{
	private:
		std::vector<int>	v;
		unsigned int		maxSize;
	public:
		Span(unsigned int size);
		~Span(void);

		std::vector<int>	getV(void) const;
		unsigned int		getMaxSize(void) const;

		void	populate(void);

		void	addNumber(int n);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

		void	print(void) const;

		template <class Iterator> void	addNumber(Iterator begin, Iterator end)
		{
			if (this->v.size() + std::abs(std::distance(begin, end)) > this->maxSize)
				throw Span::FullVectorException();
			std::copy(begin, end, std::back_inserter(this->v));
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
