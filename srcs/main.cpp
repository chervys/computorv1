/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chervy <chervy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:38:53 by chervy            #+#    #+#             */
/*   Updated: 2023/12/28 15:37:38 by chervy           ###   ########.fr       */
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

    /* Test math.hpp */
    std::cout << "### Test math.hpp ###" << std::endl;
    {
        double x = -3.14;
        std::cout << "sqrt(x)       =	" << std::sqrt(x) << std::endl;
        std::cout << "ft_sqrt(x)    =	" << ft::sqrt(x) << std::endl;
    }
    {
        double x = 3.14;
        std::cout << "sqrt(x)       =	" << std::sqrt(x) << std::endl;
        std::cout << "ft_sqrt(x)    =	" << ft::sqrt(x) << std::endl;
    }
    std::cout << std::endl;

    /* Test polynomial.hpp */
    std::cout << "### Test polynomial.hpp ###" << std::endl;
    {
        try
        {
            ft::polynomial("5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0");
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    std::cout << std::endl;
    return 0;
}
