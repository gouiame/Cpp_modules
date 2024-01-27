/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:16:09 by cgouiame          #+#    #+#             */
/*   Updated: 2023/12/01 22:02:23 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> 

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout<<"\033[32m"<<"         Printing memory addresses"<<"\033[0m"<<std::endl;
    std::cout << "Memory address of the string variable : " << &str << std::endl;
    std::cout << "Memory address held by stringPTR      : " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF      : " << &stringREF << std::endl;

    std::cout<<"\033[32m"<<"         Printing values"<<"\033[0m"<<std::endl;
    std::cout << "Value of the string variable          : " << str << std::endl;
    std::cout << "Value pointed to by stringPTR         : " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF         : " << stringREF << std::endl;

    return 0;
}