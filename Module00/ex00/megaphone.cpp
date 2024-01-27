/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:10:10 by cgouiame          #+#    #+#             */
/*   Updated: 2023/11/26 23:24:29 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str = std::string(argv[i]);
			for(int j = 0; str[j]; j++)
			{
				std::cout << (char)std::toupper(str[j]);
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}