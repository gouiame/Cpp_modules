/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:59:58 by cgouiame          #+#    #+#             */
/*   Updated: 2023/11/28 18:23:37 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zombie_ = new Zombie[N];
    for(int i = 0; i < N; i++)
    {
        zombie_[i].setname(name);
    }
    return (zombie_);
}