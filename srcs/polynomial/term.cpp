/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chervy <chervy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:54:47 by chervy            #+#    #+#             */
/*   Updated: 2024/01/08 14:02:04 by chervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term.hpp"

ft::term::term()
    : _coefficient(0)
    , _exponent(0)
{
}

ft::term::term(double coefficient, double exponent)
    : _coefficient(coefficient)
    , _exponent(exponent)
{
}

ft::term::~term() { }

double ft::term::get_coefficient() const { return this->_coefficient; }

double ft::term::get_exponent() const { return this->_exponent; }

void ft::term::set_coefficient(double coefficient)
{
    if (coefficient == 0.0)
        this->_coefficient = 0.0;
    else
        this->_coefficient = coefficient;
}
void ft::term::set_exponent(double exponent) { this->_exponent = exponent; }

void ft::term::print() const
{
    std::cout << ft::abs(this->_coefficient) << " * X^" << this->_exponent;
}

bool ft::term::operator<(const term& rhs) const
{
    if (this->get_exponent() == rhs.get_exponent())
        return this->get_coefficient() < rhs.get_coefficient();
    return this->get_exponent() < rhs.get_exponent();
}
