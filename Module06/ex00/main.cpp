/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:30:44 by cgouiame          #+#    #+#             */
/*   Updated: 2024/02/27 16:39:28 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Check args" << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
    return 0;
}
