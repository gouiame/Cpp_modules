/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:21:39 by cgouiame          #+#    #+#             */
/*   Updated: 2023/12/13 18:32:36 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout<< "Brain Default contructor called" <<std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
}

Brain::Brain(const Brain &copy)
{
	std::cout<<"Brain copy constructor called"<<std::endl;
	*this = copy;
}

Brain & Brain::operator=(const Brain &copy)
{
	// std::cout<<"Brain assignment operator called"<<std::endl;
	if (this != &copy)
	{
		for(int i = 0; i < 100; i++)
			this->ideas[i] = copy.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called"<<std::endl;
}