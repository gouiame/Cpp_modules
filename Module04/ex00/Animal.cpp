/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:51:34 by cgouiame          #+#    #+#             */
/*   Updated: 2023/12/13 16:43:19 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Defaut")
{
    std::cout<< "Animal Default contructor called" <<std::endl;
}

Animal::Animal(const Animal &copy)
{
    std::cout<<"Animal copy constructor called"<<std::endl;
    *this = copy;
}

Animal & Animal::operator=(const Animal &copy)
{
    // std::cout<<"Animal assignment operator called"<<std::endl;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called"<<std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout <<"Animal sound" <<std::endl;
}