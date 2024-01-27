/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:10:40 by cgouiame          #+#    #+#             */
/*   Updated: 2023/11/27 00:48:24 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	welcome()
{
	std::cout << std::endl;
	std::cout<<"          ************************************************************"<<std::endl;
	std::cout<<"          *             Welcome to your Awesome PhoneBook ☎          *"<<std::endl;
	std::cout<<"          ************************************************************"<<std::endl;
	std::cout<<"          * Explore your contacts seamlessly:                        *"<<std::endl;
	std::cout<<"          *  - To add a new contact, type 'ADD'.                     *"<<std::endl;
	std::cout<<"          *  - To find a contact, type 'SEARCH'.                     *"<<std::endl;
	std::cout<<"          *  - To exit, simply type 'EXIT'.                          *"<<std::endl;
	std::cout<<"          ************************************************************"<<std::endl;
}

int main ()
{
	PhoneBook Pb(0,0);
	std::string cmd; 

	welcome();
	while (1)
	{
        std::cout<<"\033[32m"<<"\n         Command: "<<"\033[0m";
        if (!std::getline(std::cin, cmd))   
            exit(0);
		if(cmd == "ADD")
			Pb.add();
		else if(cmd == "SEARCH")
		    Pb.search();
		else if(cmd == "EXIT")
			return 0;
        else
            std::cout<<"\033[31m"<<"Invalid Command, Please try again!"<<"\033[0m"<<std::endl;
	}
}
