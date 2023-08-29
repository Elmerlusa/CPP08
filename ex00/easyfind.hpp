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

template<class T> int	easyfind(T container, int x)
{
	if (std::find(container.begin(), container.end(), x) != container.end())
		return x;
	else
		throw std::runtime_error("Value not found");
}
