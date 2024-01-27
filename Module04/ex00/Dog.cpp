/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:07:11 by cgouiame          #+#    #+#             */
/*   Updated: 2023/12/13 16:48:53 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout<< "Dog Default contructor called" <<std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &copy)
{
    std::cout<<"Dog copy constructor called"<<std::endl;
    *this = copy;
}

Dog & Dog::operator=(const Dog &copy)
{
    // std::cout<<"Dog assignment operator called"<<std::endl;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called"<<std::endl;
}

void Dog::makeSound() const
{
    std::cout <<"... Woof! Woof! ..." <<std::endl;
}