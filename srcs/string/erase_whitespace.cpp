/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_whitespace.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chervy <chervy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:46:57 by chervy            #+#    #+#             */
/*   Updated: 2023/12/28 15:47:52 by chervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.hpp"

void ft::erase_whitespace(std::string &str)
{
    std::string::iterator it = str.begin();
    while (it != str.end()) {
        if (ft::is_whitespace(*it))
            str.erase(it);
        else
            it++;
    }
}
