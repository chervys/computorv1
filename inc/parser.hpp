/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chervy <chervy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:51:44 by chervy            #+#    #+#             */
/*   Updated: 2024/01/04 15:50:58 by chervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include <stdexcept>
#include <string>

namespace ft {

class parser {
private:
public:
    static double extract_double(std::string& str);
    static void check_and_erase_next_char(std::string& buffer, char character);
    static void check_and_erase_next_char(std::string& buffer,
        std::string characters);

    class syntax_error : public std::exception {
    public:
        virtual const char* what() const noexcept { return "Syntax error."; }
    };
};

} // namespace ft

#endif
