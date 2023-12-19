/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynomial.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chervy <chervy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:13:23 by chervy            #+#    #+#             */
/*   Updated: 2023/12/19 07:20:06 by chervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef POLYNOMIAL_HPP
# define POLYNOMIAL_HPP

# include <list>

# include <math.hpp>
# include <string.hpp>

namespace ft
{
    class term {
        private:
            double  _coefficient;
            double  _exponent;

        public:
            term(): _coefficient(0), _exponent(0) {
                (void) _coefficient;
                (void) _exponent;
            }
            ~term() {}
    };

    class polynomial {
        private:
            std::string     _input;
            std::list<term> _terms;

        public:
            polynomial() {}
            polynomial(std::string input): _input(input) {}
            ~polynomial() {}

        private:
            void _parser() {}
    };
}

#endif
