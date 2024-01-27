/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:36:09 by cgouiame          #+#    #+#             */
/*   Updated: 2023/11/27 01:21:10 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void    PhoneBook::add()
{
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phonenumber;
	std::string darkestsecret;
	
	std::cout<<"Insert the first name: ";
	if (!std::getline(std::cin, firstname))
		exit(0);
	std::cout<<"Insert the last name: ";
	if (!std::getline(std::cin, lastname))
		exit(0);
	std::cout<<"Insert the nickname: ";
	if (!std::getline(std::cin, nickname))
		exit(0);
	std::cout<<"Insert the phone number: ";
	if (!std::getline(std::cin, phonenumber))
		exit(0);
	std::cout<<"Insert the darkest secret: ";
	if (!std::getline(std::cin, darkestsecret))
		exit(0);
	
	if (firstname == "" || lastname == "" || nickname == "" || phonenumber == "" || darkestsecret == "")
		{
			std::cout<<"\033[31m"<<"Please complete all required fields."<<"\033[0m"<<std::endl;
			return ;
		}
	this->contacts[idx].setIndex(idx);
	this->contacts[idx].setFirstName(firstname);
	this->contacts[idx].setLastName(lastname);
	this->contacts[idx].setNickName(nickname);
	this->contacts[idx].setPhoneNumber(phonenumber);
	this->contacts[idx].setDarkestSecret(darkestsecret);

	this->idx += 1;
	this->count += 1;
	if (this->idx == 8)
		this->idx = 0;
}

void	printline(std::string str)
{
	  int len = str.length();

    if (len == 10)
        std::cout<< "|" << str;
    else if (len < 10)
        std::cout << "|" << std::setw(10) << str;
    else
        std::cout << "|" << str.substr(0, 9) << ".";
}

void	PhoneBook::display()
{
	int i = 0;
	int nb;

	if(this->count >= 8)
		nb = 8;
	else
		nb = this->idx;
	while(i < nb)
	{
		std::cout <<std::setw(10)<< this->contacts[i].getIndex();
		printline(this->contacts[i].getFirstName());
		printline(this->contacts[i].getLastName());
		printline(this->contacts[i].getNickName());
		std::cout << "|" << std::endl;
		i++;
	}
}

void	PhoneBook::infoscontact(std::string nb)
{
	int i = nb[0] - '0';
	std::cout << "Index			: " << this->contacts[i].getIndex() << std::endl;
	std::cout << "First Name		: " << this->contacts[i].getFirstName() << std::endl;
	std::cout << "Last Name		: " << this->contacts[i].getLastName() << std::endl;
	std::cout << "Nickname		: " << this->contacts[i].getNickName() << std::endl;
	std::cout << "Phone Number		: " << this->contacts[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret		: " << this->contacts[i].getDarkestSecret() << std::endl;
}

void    PhoneBook::search()
{
	std::string index_c;
	int	idx;
	if (this->count == 0)
	{
		std::cout<<"\033[31m" << "Add some contacts to bring your phonebook to life!"<<"\033[0m"<<std::endl;
		return ;
	}
	display();
	std::cout << "Please enter the contact index : ";
	if(!std::getline(std::cin, index_c))
		exit(0);
	if (index_c.length() != 1 || index_c[0] < 48 || index_c[0]> 55)
	{
		std::cout<<"\033[31m" << "Index not found. Please try again."<<"\033[0m"<<std::endl;
		return ;
	}
	idx = index_c[0] - '0';
	if (idx >= this->count)
    {
        std::cout<<"\033[31m" << "Index not found. Please try again."<<"\033[0m" << std::endl;
        return;
    }
	infoscontact(index_c);
}

PhoneBook::PhoneBook(int idx, int count)
{
	this->idx = idx;
	this->count = count;
}
PhoneBook::~PhoneBook(){}
