/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chervy <chervy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:13:23 by chervy            #+#    #+#             */
/*   Updated: 2023/12/15 16:32:37 by chervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRING_HPP
# define STRING_HPP

# include <string>

namespace ft
{
    int is_digit(char c)
    {
        return c >= '0' && c <= '9';
    }
    
    int is_white_space(char c)
    {
        return (c >= 9 && c <= 13) || c == 32;
    }

    void trim_whitespace(std::string &str)
    {
        std::string::iterator it = str.begin();
        while (it != str.end()) {
            if (is_white_space(*it))
                str.erase(it);
            else
                it++;
        }
    }
}

#endif