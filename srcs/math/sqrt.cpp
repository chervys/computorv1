/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqrt.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chervy <chervy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:44:31 by chervy            #+#    #+#             */
/*   Updated: 2024/01/04 15:49:01 by chervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.hpp"

// Square root with Heron's method.
double ft::sqrt(double x)
{
    double a = x; // upper bound
    double b = 0; // lower bound
    double epsilon = 1.0E-64;
    double precision = ft::abs(a - b);
    double precision_old = 0;

    if (x < 0) {
        return std::numeric_limits<double>::signaling_NaN();
    }
    while (precision > epsilon) {
        a = a / 2 + b / 2;
        b = x / a;
        precision_old = precision;
        precision = ft::abs(a - b);
        if (precision == precision_old) {
            break;
        }
    }
    if (ft::abs((a * a) - x) > ft::abs((b * b) - x))
        return (b);
    return (a);
}
