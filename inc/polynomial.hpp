/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynomial.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chervy <chervy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:13:23 by chervy            #+#    #+#             */
/*   Updated: 2023/12/28 15:57:10 by chervy           ###   ########.fr       */
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

            bool get_sign() const {
                return this->_coefficient >= 0;
            }

            void print() const {
                std::cout << ft::abs(this->_coefficient) << " * X^" << this->_exponent;
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
            int             _degree;
            double          _discriminant;
            
            polynomial() {}
            
        public:
            polynomial(std::string input): _input(input) {
                (void) this->_degree;
                (void) this->_discriminant;
                this->_parser();
                this->_reduce();
                this->_check_exponent();
                this->_init_degree();
                this->_init_discriminant();
                this->_print();
            }
            ~polynomial() {}

        private:
            void _solve() {
                
            }
            
            void _check_exponent() {
                std::list<term>::const_iterator current = this->_terms.cbegin();
                std::list<term>::const_iterator end = this->_terms.cend();
                double a(0), b(0);

                while (current != end) {
                    a = current->get_exponent();
                    b = (int)a;
                    if (a != b)
                        throw syntax_error();
                    current++;
                }
            }

            void _init_degree() {
                std::list<term>::const_iterator last = std::prev(this->_terms.cend());
                double a = last->get_exponent();
                double b = (int) a;

                if (a == b) {
                    this->_degree = b;
                }
            }

            void _init_discriminant() {
                if (this->_degree == 2) {
                    std::list<term>::const_iterator current = this->_terms.cbegin();
                    std::list<term>::const_iterator end = this->_terms.cend();

                    double a(0), b(0), c(0);

                    while (current != end) {
                        switch ((int) current->get_exponent())
                        {
                        case 0:
                            c = current->get_coefficient();
                            break;
                        case 1:
                            b = current->get_coefficient();
                            break;
                        case 2:
                            a = current->get_coefficient();
                            break;
                        
                        default:
                            break;
                        }
                        current++;
                    }
                    
                    this->_discriminant = (b * b) - (4 * a * c);
                    std::cout << this->_discriminant << std::endl;
                }
            }

            void _reduce() {
                std::list<term>::iterator   current = this->_terms.begin();
                std::list<term>::iterator   end = this->_terms.end();
                std::list<term>::iterator   next;

                while (current != end) {
                    next = std::next(current);
                    if (next != end && current->get_exponent() == next->get_exponent()) {
                        current->set_coefficient(
                            current->get_coefficient() + next->get_coefficient()
                        );
                        this->_terms.erase(next);
                    }
                    else
                        current++;
                }
            }
         
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

            void _print_reduce() const {
                std::list<term>::const_iterator current = this->_terms.cbegin();
                std::list<term>::const_iterator next = std::next(current);
                std::list<term>::const_iterator end = this->_terms.cend();

                std::cout << "Reduce form: ";

                while (current != end) {
                    current->print();
                    if (next != end && next->get_coefficient() < 0) {
                        std::cout << " - ";
                    }
                    else if (next != end) {
                        std::cout << " + ";
                    }
                    current++;
                    next = std::next(current);
                }
                if (current == end) {
                    std::cout << " = 0";
                }
                std::cout << std::endl;
            }

            void _print_degree() const {
                std::cout << "Polynomial degree : " << this->_degree << std::endl;
            }

            void _print_solutions() const {
                
            }

            void _print() const {
                this->_print_reduce();
                this->_print_degree();
                this->_print_solutions();
            }
    };
}

#endif
