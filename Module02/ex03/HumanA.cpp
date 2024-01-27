/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:52:52 by cgouiame          #+#    #+#             */
/*   Updated: 2023/11/30 17:36:32 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &_weapon) : _weapon(_weapon)
{
    this->name = name;
}

HumanA::~HumanA(){}

void    HumanA::attack()
{
    std::cout<< this->name << " attacks with their " << this->_weapon.getType() << std::endl;
}