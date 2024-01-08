/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chervy <chervy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:38:53 by chervy            #+#    #+#             */
/*   Updated: 2024/01/08 14:30:36 by chervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.hpp"

#include <iostream>

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    if (argc != 2) {
        std::cout << "Invalid arguments." << std::endl;
        return -1;
    }

    try {
        ft::polynomial(std::string(argv[1]));
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
