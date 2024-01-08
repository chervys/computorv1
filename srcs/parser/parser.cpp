/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chervy <chervy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:41:02 by chervy            #+#    #+#             */
/*   Updated: 2024/01/04 21:38:50 by chervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.hpp"

double ft::parser::extract_double(std::string& str)
{
    size_t i = 0;
    double x = NAN;

    x = std::stod(str, &i);
    str.erase(0, i);

    return x;
}

void ft::parser::check_and_erase_next_char(std::string& buffer,
    char character)
{
    if (buffer.empty() == false && buffer[0] == character)
        buffer.erase(0, 1);
    else
        throw syntax_error();
}

void ft::parser::check_and_erase_next_char(std::string& buffer,
    std::string characters)
{
    if (buffer.empty() == false && characters.find(buffer[0]) != std::string::npos)
        buffer.erase(0, 1);
    else
        throw syntax_error();
}
