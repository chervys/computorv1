/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chervy <chervy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:00:31 by chervy            #+#    #+#             */
/*   Updated: 2023/12/14 15:13:16 by chervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_HPP
# define MATH_HPP

namespace ft {
	// Absolute value
	double abs(double x) {
		if (x >= 0)
			return (x);
		else
			return (-x);
	}

	// Square root with Heron's method.
	double sqrt(double x) {
		double	a = x;	// upper bound
		double	b = 0;	// lower bound
		double	epsilon = 1.0E-64;
		double	precision = abs(a - b);
		double	precision_old = 0;
	
		if (x < 0) {
			return NAN;
		}
		while (precision > epsilon) {
			a = a / 2 + b / 2;
			b = x / a;
			precision_old = precision;
			precision = abs(a - b);
			if (precision == precision_old) {
				break;
			}
		}
		if (abs((a * a) - x) > abs((b * b) - x))
			return (b);
		return (a);
	}
}

#endif
