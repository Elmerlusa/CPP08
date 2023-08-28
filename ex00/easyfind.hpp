#pragma once

#include <algorithm>
#include <stdexcept>

template<class T> int	easyfind(T container, int x)
{
	if (std::find(container.begin(), container.end(), x) != container.end())
		return x;
	else
		throw std::runtime_error("Value not found");
}
