/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:02:19 by cgouiame          #+#    #+#             */
/*   Updated: 2023/12/02 16:10:11 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
int main()
{
    int N;
    std::cout << "Enter the size of zombies : ";
    std::cin >> N;
    if (!std::cin)
        exit(0);
    Zombie *horde = zombieHorde(N, "Horde of Zombies!");
    for (int i = 0; i < N ; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
    return 0;
}
