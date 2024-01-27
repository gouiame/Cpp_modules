/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:00:30 by cgouiame          #+#    #+#             */
/*   Updated: 2023/12/01 21:45:29 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

Replace::Replace(){}

Replace::~Replace(){}


void Replace::ft_replace(std::string filename, std::string s1, std::string s2)
{
    std::ifstream input_file(filename);
    if (!input_file)
    {
        std::cerr << "Error: Unable to open input file\n";
        return;
    }

    std::ofstream output_file(filename + ".replace");
    if (!output_file)
    {
        std::cerr << "Error: Unable to create output file\n";
        return;
    }

    std::string line;
    while (std::getline(input_file, line))
    {
        size_t found = line.find(s1);
        while (found != std::string::npos)
        {
            line.erase(found, s1.length());
            line.insert(found, s2);
            found = line.find(s1, found + s2.length());
        }
        output_file << line <<std::endl;
    }
    input_file.close();
    output_file.close();
    std::cout << "File '" << filename << "' has been saved as '" << filename + ".replace" << "'\n";
}