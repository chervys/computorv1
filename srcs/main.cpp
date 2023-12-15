/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chervy <chervy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:38:53 by chervy            #+#    #+#             */
/*   Updated: 2023/12/15 16:07:13 by chervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <math.h>

#include <computorv1.hpp>

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    std::cout << std::endl;

    /* Test Math.hpp */
    {
        std::cout << "### Test Math.hpp ###" << std::endl;
        double x = -3.14;

        std::cout << "sqrt(x) =	" << std::sqrt(x) << std::endl;
        std::cout << "ft_sqrt(x) =	" << ft::sqrt(x) << std::endl;
    }

    std::cout << std::endl;
    return 0;
}
