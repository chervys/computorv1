/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynomial.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chervy <chervy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:42:42 by chervy            #+#    #+#             */
/*   Updated: 2024/01/09 16:31:52 by chervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polynomial.hpp"

ft::polynomial::polynomial() { }

ft::polynomial::polynomial(std::string input)
    : _input(input)
{
    this->_parser();
    this->_check_exponent();
    this->_reduce();
    this->_init_degree();
    this->_print();
    this->_solve();
}

ft::polynomial::~polynomial() { }

void ft::polynomial::_solve()
{
    std::list<term>::const_iterator current = this->_terms.cbegin();
    std::list<term>::const_iterator end = this->_terms.cend();
    double a(0), b(0), c(0);

    if (this->_degree == 2) {
        while (current != end) {
            switch ((int)current->get_exponent()) {
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
        // std::cout << "Discrimant : " << this->_discriminant << std::endl;

        if (this->_discriminant > 0) {
            double r = ft::sqrt(this->_discriminant);
            double x1 = (-b - r) / (2 * a);
            double x2 = (-b + r) / (2 * a);

            std::cout << "Discriminant is strictly positive, the two solutions are :" << std::endl;
            std::cout << "x1 = " << x1 << std::endl;
            std::cout << "x2 = " << x2 << std::endl;
        } else if (this->_discriminant == 0) {
            double x = (-b) / (2 * a);

            std::cout << "Discriminant is equal to zero, the solution is :" << std::endl;
            std::cout << "x = " << x << std::endl;
        } else {
            std::cout << "Discriminant is strictly negative, the two solutions are :" << std::endl;
            std::cout << "x1 = "
                      << "(" << -b << " - i * sqrt(" << ft::abs(this->_discriminant) << ")) / " << 2 * a << std::endl;
            std::cout << "x2 = "
                      << "(" << -b << " + i * sqrt(" << ft::abs(this->_discriminant) << ")) / " << 2 * a << std::endl;
        }
    } else if (this->_degree == 1) {
        while (current != end) {
            switch ((int)current->get_exponent()) {
            case 0:
                b = current->get_coefficient();
                break;
            case 1:
                a = current->get_coefficient();
                break;

            default:
                break;
            }
            current++;
        }

        std::cout << "The solution is :" << std::endl;
        if (b == 0)
            std::cout << a << std::endl;
        else
            std::cout << b / a << std::endl;
    } else if (this->_degree == 0) {
        if (this->_terms.begin()->get_coefficient() == 0)
            std::cout << "The set of real numbers are solutions." << std::endl;
        else
            std::cout << "There is no solution." << std::endl;
    } else {
        std::cout << "The polynomial degree is strictly greater than 2, I can't solve." << std::endl;
    }
}

void ft::polynomial::_check_exponent()
{
    std::list<term>::const_iterator current = this->_terms.cbegin();
    std::list<term>::const_iterator end = this->_terms.cend();
    double a(0), b(0);

    while (current != end) {
        a = current->get_exponent();
        b = (int)a;
        if (a != b || a < 0)
            throw parser::syntax_error();
        current++;
    }
}

void ft::polynomial::_init_degree()
{
    if (this->_terms.size() == 0) {
        this->_degree = 0;
        return;
    }

    std::list<term>::const_iterator last = std::prev(this->_terms.cend());
    double a = last->get_exponent();
    double b = (int)a;

    if (a == b) {
        this->_degree = b;
    }
}

void ft::polynomial::_reduce()
{
    std::list<term>::iterator current = this->_terms.begin();
    std::list<term>::iterator end = this->_terms.end();
    std::list<term>::iterator next;

    while (current != end) {
        next = std::next(current);
        if (next != end && current->get_exponent() == next->get_exponent()) {
            current->set_coefficient(current->get_coefficient() + next->get_coefficient());
            this->_terms.erase(next);
        } else
            current++;
    }

    std::list<term>::iterator last = std::prev(this->_terms.end());
    while (last->get_coefficient() == 0 && this->_terms.size() > 1) {
        this->_terms.erase(last);
        last = std::prev(this->_terms.end());
    }
}

void ft::polynomial::_parser()
{
    int side = LEFT;

    if (this->_input.length() == 0)
        throw ft::parser::syntax_error();

    ft::erase_whitespace(this->_input);

    while (this->_input.empty() == false) {
        this->_check_and_up_side(side);
        this->_terms.push_front(this->_get_next_term(this->_input, side));
        this->_check_and_up_side(side);
    }

    if (side == LEFT)
        throw ft::parser::syntax_error();

    this->_terms.sort();
}

void ft::polynomial::_check_and_up_side(int& side)
{
    if (this->_input.empty() == false && this->_input[0] == '=') {
        if (side == RIGHT)
            throw parser::syntax_error();
        side = RIGHT;
        ft::parser::check_and_erase_next_char(this->_input, "=");
    }
}

ft::term ft::polynomial::_get_next_term(std::string& str, int side)
{
    ft::term tmp;

    tmp.set_coefficient(ft::parser::extract_double(str) * side);
    ft::parser::check_and_erase_next_char(str, '*');
    ft::parser::check_and_erase_next_char(str, "Xx");
    ft::parser::check_and_erase_next_char(str, '^');
    tmp.set_exponent(ft::parser::extract_double(str));

    return tmp;
}

void ft::polynomial::_print_reduce() const
{
    std::list<term>::const_iterator current = this->_terms.cbegin();
    std::list<term>::const_iterator next = std::next(current);
    std::list<term>::const_iterator end = this->_terms.cend();

    std::cout << "Reduce form: ";

    if (this->_terms.size() == 0) {
        return;
    }

    if (current->get_coefficient() < 0)
        std::cout << "-";
    while (current != end) {
        current->print();
        if (next != end && next->get_coefficient() < 0) {
            std::cout << " - ";
        } else if (next != end) {
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

void ft::polynomial::_print_degree() const
{
    std::cout << "Polynomial degree : " << this->_degree << std::endl;
}

void ft::polynomial::_print() const
{
    this->_print_reduce();
    this->_print_degree();
}
