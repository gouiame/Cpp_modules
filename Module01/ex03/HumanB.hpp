/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:53:02 by cgouiame          #+#    #+#             */
/*   Updated: 2023/12/02 16:10:45 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
    private :
        std::string name;
        Weapon *_weapon;
    public :
        HumanB(std::string name);
        ~HumanB();
        void attack();
        void setWeapon(Weapon &_weapon);
};

#endif