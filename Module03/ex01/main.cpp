/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:58:44 by cgouiame          #+#    #+#             */
/*   Updated: 2023/12/10 21:51:48 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
// #include "ClapTrap.hpp"

int main()
{
    ScavTrap Scav("A");
    Scav.takeDamage(5);
    Scav.beRepaired(6);
    Scav.guardGate();
}