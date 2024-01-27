/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:03:28 by cgouiame          #+#    #+#             */
/*   Updated: 2023/12/13 16:41:13 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    
    delete meta;
    delete j;
    delete i;
    
    std::cout<<std::endl<<"------------------------------------------------------"<<std::endl;
    
    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* w_cat = new WrongCat();
    std::cout << wrong->getType() << " " << std::endl;
    std::cout << w_cat->getType() << " " << std::endl;
    wrong->makeSound();
    w_cat->makeSound();
    
    delete wrong;
    delete w_cat;
    return 0;   
}