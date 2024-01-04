/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chervy <chervy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:13:23 by chervy            #+#    #+#             */
/*   Updated: 2024/01/04 15:48:45 by chervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_HPP
#define STRING_HPP

#include <string>

namespace ft {

int is_digit(char c);
int is_whitespace(char c);
void erase_whitespace(std::string& str);

} // namespace ft

#endif
