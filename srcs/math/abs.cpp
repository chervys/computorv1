/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chervy <chervy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:40:42 by chervy            #+#    #+#             */
/*   Updated: 2024/01/04 15:48:55 by chervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.hpp"

// Absolute value
double ft::abs(double x)
{
    if (x >= 0)
        return (x);
    else
        return (-x);
}