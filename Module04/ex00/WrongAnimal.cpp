/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:03:35 by cgouiame          #+#    #+#             */
/*   Updated: 2023/12/13 18:31:34 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout<< "WrongAnimal Default contructor called" <<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout<<"WrongAnimal copy constructor called"<<std::endl;
    *this = copy;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal &copy)
{
    // std::cout<<"WrongAnimal assignment operator called"<<std::endl;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called"<<std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}

void WrongAnimal::makeSound() const
{
    std::cout <<"WrongAnimal sound" <<std::endl;
}