/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:10:36 by cgouiame          #+#    #+#             */
/*   Updated: 2023/11/27 00:18:33 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Contact {
	private:
		int			Index;
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string PhoneNumber;
		std::string DarkestSecret;
	public:
		Contact();
		~Contact();
		void		setIndex(int Index);
		void		setFirstName(std::string FirstName);
		void		setLastName(std::string LastName);
		void		setNickName(std::string NickName);
		void		setPhoneNumber(std::string PhoneNumber);
		void		setDarkestSecret(std::string DarkestSecret);
		int			getIndex();
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickName();
		std::string	getPhoneNumber();
		std::string	getDarkestSecret();
};