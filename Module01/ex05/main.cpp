/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:05:11 by cgouiame          #+#    #+#             */
/*   Updated: 2023/12/02 16:06:53 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;
    std::string input;

    while(1)
    {
        std::cout <<"Enter a level : ";
        if (!std::getline(std::cin, input))
            return 0;
        if (input.empty())
            continue ;
        harl.complain(input); 
    }
}