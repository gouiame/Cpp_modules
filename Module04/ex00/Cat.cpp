/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:07:09 by cgouiame          #+#    #+#             */
/*   Updated: 2023/12/13 18:29:53 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout<< "Cat Default contructor called" <<std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &copy)
{
    std::cout<<"Cat copy constructor called"<<std::endl;
    *this = copy;
}

Cat & Cat::operator=(const Cat &copy)
{
    // std::cout<<"Cat assignment operator called"<<std::endl;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called"<<std::endl;
}

void Cat::makeSound() const
{
    std::cout <<"... Meow! Meow!..." <<std::endl;
}