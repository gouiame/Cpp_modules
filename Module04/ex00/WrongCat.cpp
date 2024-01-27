/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:03:42 by cgouiame          #+#    #+#             */
/*   Updated: 2023/12/13 18:32:09 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout<< "WrongCat Default contructor called" <<std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy)
{
    std::cout<<"WrongCat copy constructor called"<<std::endl;
    *this = copy;
}

WrongCat & WrongCat::operator=(const WrongCat &copy)
{
    // std::cout<<"WrongCat assignment operator called"<<std::endl;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called"<<std::endl;
}

void WrongCat::makeSound() const
{
    std::cout <<"... Meow! Meow!..." <<std::endl;
}