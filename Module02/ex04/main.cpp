/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:00:35 by cgouiame          #+#    #+#             */
/*   Updated: 2023/12/01 22:18:58 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int argc, char **argv)
{
    Replace Rep;
    if (argc != 4)
    {
        std::cerr <<"Error : check args"<<std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (filename.empty() || s1.empty() || s2.empty())
    {
        std::cerr << "Error : arguments cannot be empty"<<std::endl;
        return 1;
    }
    Rep.ft_replace(filename, s1, s2);

    return 0;
}