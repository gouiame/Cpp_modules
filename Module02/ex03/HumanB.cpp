/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:52:43 by cgouiame          #+#    #+#             */
/*   Updated: 2023/12/01 22:06:40 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
}

HumanB::~HumanB(){}

void    HumanB::setWeapon(Weapon &_weapon)
{
    this->_weapon = &_weapon;
}

void    HumanB::attack()
{
    std::cout<< this->name << " attacks with their " << this->_weapon->getType() << std::endl;
}