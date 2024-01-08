/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynomial.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chervy <chervy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:13:23 by chervy            #+#    #+#             */
/*   Updated: 2024/01/04 15:52:09 by chervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <iostream>
#include <list>
#include <stdexcept>

#include "math.hpp"
#include "parser.hpp"
#include "string.hpp"

namespace ft {

enum side {
    LEFT = 1,
    RIGHT = -1,
};

class term {
private:
    double _coefficient;
    double _exponent;

public:
    term();
    term(double coefficient, double exponent);
    ~term();

    double get_coefficient() const;
    double get_exponent() const;
    void set_coefficient(double coefficient);
    void set_exponent(double exponent);
    void print() const;
    bool operator<(const term& rhs) const;
};

class polynomial {
private:
    std::string _input;
    std::list<term> _terms;
    int _degree;
    double _discriminant;

    polynomial();

public:
    polynomial(std::string input);
    ~polynomial();

private:
    void _solve();
    void _check_exponent();
    void _init_degree();
    void _init_discriminant();
    void _reduce();

    term _get_next_term(std::string& str, int side);
    void _check_and_up_side(int& side);
    void _parser();

    void _print_reduce() const;
    void _print_degree() const;
    void _print_solutions() const;
    void _print() const;
};

} // namespace ft

#endif
