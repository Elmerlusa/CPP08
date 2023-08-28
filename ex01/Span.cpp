#include "Span.hpp"

Span::Span(unsigned int size): v(std::vector<int>()), maxSize(size)
{
}

Span::~Span(void)
{
}

std::vector<int>	Span::getV(void) const
{
	return this->v;
}

unsigned int	Span::getMaxSize(void) const
{
	return this->maxSize;
}

void	Span::populate(void)
{
	if (this->v.size() == this->maxSize)
		return ;
	std::srand((int)time(NULL));
	for (unsigned int i = this->v.size(); i < this->maxSize; i++)
		this->v.push_back(std::rand());
}

void	Span::addNumber(int num) 
{
	if (this->v.size() == this->maxSize)
		throw Span::FullVectorException();
	this->v.push_back(num);
}

int	Span::shortestSpan(void) const
{
	std::vector<int>	vAux(this->v.size(), 0);
	int					shortestSpan;
	
	if (this->v.size() <= 1)
		throw Span::NoSpanFoundException();
	std::partial_sort_copy(this->v.begin(), this->v.end(), vAux.begin(), vAux.end());
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
	if (this->v.size() <= 1)
		throw Span::NoSpanFoundException();
	return *std::max_element(this->v.begin(), this->v.end()) - *std::min_element(this->v.begin(), this->v.end());
}

void	Span::print(void) const
{
	std::cout << "Span(" << this->maxSize << "): ";
	for (std::vector<int>::const_iterator it = this->v.begin(); it != this->v.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;
}

const char*	Span::FullVectorException::what(void) const throw()
{
	return "The array is full of numbers";
}

const char*	Span::NoSpanFoundException::what(void) const throw()
{
	return "No span can be found";
}
