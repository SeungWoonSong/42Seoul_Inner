/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:32:29 by susong            #+#    #+#             */
/*   Updated: 2023/01/09 13:30:11 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook contact[8];
	std::string input = "";

	while(input != "EXIT")
	{
		std::cout << BLUE << "Choose Action : ADD, SEARCH, EXIT\n" << "Input : " << RESET;
		std::getline(std::cin, input);
		if(input == "ADD")
			PhoneBook::addContact(contact[PhoneBook::getCount()]);
		else if(input == "SEARCH")
			PhoneBook::showSearch(contact);
		else if(input == "EXIT")
			std::cout << YELLOW << "GOOD BYE" << std::endl;

		else
			std::cout << RED << "Choose in option " << YELLOW << input << RED << " cannot be executed" << RESET << std::endl;
	}
	return (0);
}
