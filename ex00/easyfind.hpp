/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:33:31 by javmarti          #+#    #+#             */
/*   Updated: 2023/08/28 15:33:32 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <stdexcept>

template<class T> const int&	easyfind(T container, int x)
{
	typename T::iterator	result;

	result = std::find(container.begin(), container.end(), x);
	if (result != container.end())
		return *result;
	else
		throw std::runtime_error("Value not found");
}
