/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:21:23 by cgouiame          #+#    #+#             */
/*   Updated: 2023/12/01 21:29:47 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::string name;
    std::cout<<"\033[32m" << "           Creating a Zombie on the stack"<<"\033[0m"<<std::endl;
    std::cout << "Enter the name of Zombie : ";
    if (!std::getline(std::cin, name))
        exit(0);
    randomChump(name);

    std::cout <<"\033[32m"<< "           Creating a Zombie on the heap"<<"\033[0m"<<std::endl;
    std::cout <<"Enter the name of Zombie : ";
    if (!std::getline(std::cin, name))
        exit(0);
    Zombie *zombiee = newZombie(name);
    zombiee->announce();
    delete zombiee;
    return 0;
}