/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chervy <chervy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:01:16 by chervy            #+#    #+#             */
/*   Updated: 2024/01/08 14:02:35 by chervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_HPP
#define TERM_HPP

#include <iostream>
#include <list>
#include <stdexcept>

#include "math.hpp"
#include "parser.hpp"
#include "string.hpp"

namespace ft {

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

} // namespace ft

#endif
