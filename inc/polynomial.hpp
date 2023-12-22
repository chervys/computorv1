/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynomial.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chervy <chervy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:13:23 by chervy            #+#    #+#             */
/*   Updated: 2023/12/22 16:04:35 by chervy           ###   ########.fr       */
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
    enum side {
        LEFT = 1,
        RIGHT = -1,
    };
    
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

            void set_coefficient(double coefficient) {
                if (coefficient == 0.)
                    this->_coefficient = 0.;
                else
                    this->_coefficient = coefficient;
            }
            void set_exponent(double exponent) {
                this->_exponent = exponent;
            }
    };

	bool operator<(const term& lhs, const term& rhs) {
        if (lhs.get_exponent() == rhs.get_exponent())
            return lhs.get_coefficient() < rhs.get_coefficient();
		return lhs.get_exponent() < rhs.get_exponent();
	}

    class polynomial {
        private:
            std::string     _input;
            std::list<term> _terms;
            
            polynomial() {}
            
        public:
            polynomial(std::string input): _input(input) {
                std::cout << this->_input << std::endl;
                _parser();
                _print_terms();
            }
            ~polynomial() {}

        private:
            void _parser() {
                int side = LEFT;
                
                ft::erase_whitespace(this->_input);

                while (this->_input.empty() == false) {
                    this->_check_and_up_side(side);
                    this->_terms.push_front(
                        this->_get_next_term(this->_input, side)
                    );
                    this->_check_and_up_side(side);
                }

                this->_terms.sort();
            }

            void _check_and_up_side(int &side) {
                if (this->_input.empty() == false && this->_input[0] == '=') {
                    if (side == RIGHT)
                        throw syntax_error();
                    side = RIGHT;
                    ft::parser::check_and_erase_next_char(this->_input, "=");
                }
            }

            term _get_next_term(std::string &str, int side) {
                term tmp;

                tmp.set_coefficient(ft::parser::extract_double(str) * side);
                ft::parser::check_and_erase_next_char(str, '*');
                ft::parser::check_and_erase_next_char(str, "Xx");
                ft::parser::check_and_erase_next_char(str, '^');
                tmp.set_exponent(ft::parser::extract_double(str));

                return tmp;
            }

            void _print_terms() const {
                std::list<term>::const_iterator current = this->_terms.cbegin();
                std::list<term>::const_iterator end = this->_terms.cend();

                while (current != end) {
                    std::cout << current->get_coefficient() << "X^" << current->get_exponent() << std::endl;
                    current++;
                }
            }
    };
}

#endif
