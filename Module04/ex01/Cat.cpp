/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:21:43 by cgouiame          #+#    #+#             */
/*   Updated: 2023/12/13 18:29:55 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout<< "Cat Default contructor called" <<std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat &copy)
{
    std::cout<<"Cat copy constructor called"<<std::endl;
    this->type = copy.type;
    this->brain = new Brain();
    for (int i = 0; i < 100; i++)
        brain[i] = copy.brain[i];
}

Cat & Cat::operator=(const Cat &copy)
{
    // std::cout<<"Cat assignment operator called"<<std::endl;
    this->type = copy.type;
    if (this->brain)
        delete brain;
    brain = new Brain();
    for (int i = 0; i < 100; i++)
        brain[i] = copy.brain[i];
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called"<<std::endl;
    delete this->brain;
}

void Cat::makeSound() const
{
    std::cout <<"... Meow! Meow!..." <<std::endl;
}