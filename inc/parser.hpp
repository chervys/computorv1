/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chervy <chervy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:51:44 by chervy            #+#    #+#             */
/*   Updated: 2023/12/20 22:33:07 by chervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
# define PARSER_HPP

# include <string>
# include <stdexcept>

namespace ft
{
    class parser {
        private:
        public:
            static double extract_double(std::string &str) {
                size_t  i = 0;
                double  x = NAN;

                x = std::stod(str, &i);
                str.erase(0, i);

                return x;
            }

            static void check_and_erase_next_char(std::string &buffer, char character) {
                if (buffer.length() > 0 && buffer[0] == character)
                    buffer.erase(0, 1);
                else
                    throw syntax_error();
            }

            static void check_and_erase_next_char(std::string &buffer, std::string characters) {
                if (buffer.length() > 0 && characters.find(buffer[0]) != std::string::npos)
                    buffer.erase(0, 1);
                else
                    throw syntax_error();
            }

            class syntax_error : public std::exception {
                public:
                    virtual const char* what() const noexcept {
                        return "Syntax error.";
                    }
            };
    };
}

#endif