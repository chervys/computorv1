/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynomial.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chervy <chervy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:13:23 by chervy            #+#    #+#             */
/*   Updated: 2023/12/20 22:35:06 by chervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYNOMIAL_HPP
# define POLYNOMIAL_HPP

# include <list>
# include <stdexcept>

# include <math.hpp>
# include <string.hpp>
# include <parser.hpp>

namespace ft
{
    class syntax_error : public std::exception {
        public:
            virtual const char* what() const noexcept {
                return "Syntax error.";
            }
    };
    
    class term {
        private:
            double  _coefficient;
            double  _exponent;

        public:
            term(): _coefficient(0), _exponent(0) {}
            term(double coefficient, double exponent)
                : _coefficient(coefficient), _exponent(exponent) {}
            ~term() {}

            double get_coefficient() const {
                return this->_coefficient;
            }
            double get_exponent() const {
                return this->_exponent;
            }
    };

    class polynomial {
        private:
            std::string     _input;
            std::list<term> _terms;
            
            polynomial() {}
            
        public:
            polynomial(std::string input): _input(input) {
                _parser();
            }
            ~polynomial() {}

        private:
            void _parser() {
                int side = 1;
                std::cout << this->_input << std::endl;
                
                ft::erase_whitespace(this->_input);
                std::cout << this->_input << std::endl;
                
                while (this->_input.empty() == false) {
                    this->_get_next_term(this->_input, side);
                }
            }

            term _get_next_term(std::string &str, int) {
                term t;

                // Double
                ft::parser::extract_double(str);
                std::cout << this->_input << std::endl;

                // Char -> *
                ft::parser::check_and_erase_next_char(str, '*');
                std::cout << this->_input << std::endl;

                // Char -> xX
                ft::parser::check_and_erase_next_char(str, "Xx");
                std::cout << this->_input << std::endl;

                // Char -> ^
                ft::parser::check_and_erase_next_char(str, '^');
                std::cout << this->_input << std::endl;

                // Double
                ft::parser::extract_double(str);
                std::cout << this->_input << std::endl;

                return t;
            }
    };
}

#endif
