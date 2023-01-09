/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:19:02 by susong            #+#    #+#             */
/*   Updated: 2023/01/09 13:26:17 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"

int PhoneBook::count = 0;
int	PhoneBook::full = 0;

PhoneBook::PhoneBook(){
	std::string	_firstName = "";
	std::string	_lastName = "";
	std::string	_nickName = "";
	std::string	_phoneNumber = "";
	std::string	_darkestSecret = "";
	// std::cout << "Create Contact" <<std::endl;
}

PhoneBook::~PhoneBook()
{
	// std::cout << "소멸자 생성" << std::endl;
	return ;
}

void	PhoneBook::addContact(PhoneBook &contact)
{
	PhoneBook::indexPlus();
	contact.putData("FISRT NAME", contact._firstName);
	contact.putData("LAST NAME", contact._lastName);
	contact.putData("NICK NAME", contact._nickName);
	contact.putData("PHONE NUMBER", contact._phoneNumber);
	contact.putData("DARKEST SECRET", contact._darkestSecret);

	if(PhoneBook::count == 8)
	{
		std::cout << RED << "Now Phone Book is Full. Next add will replace contact 0" << RESET << std::endl;
		PhoneBook::indexReset();
		PhoneBook::full = 1;
	}
	return ;
}

void	PhoneBook::indexReset()
{
	count = 0;
	return ;
}
void	PhoneBook::indexPlus()
{
	count++;
	return ;
}
int		PhoneBook::getCount()
{
	return PhoneBook::count;
}

void	PhoneBook::putData(std::string dataType, std::string &dest)
{
	std::cout << BLUE << "Put DATA of " << dataType << RESET << std::endl;
	getline(std::cin,dest);
	while(dest == "")
	{
		std::cout << RED << "Empty field is not allowd" << RESET << std::endl;
		std::cout << BLUE << "Input : " ;
		getline(std::cin, dest);
		std::cout << std::endl;
	}
	return ;
}

void	PhoneBook::showSearch(PhoneBook *contact)
{
	int	size = PhoneBook::full == 1 ? 8 : PhoneBook::count;
	if(size == 0 && PhoneBook::full == 0)
	{
		std::cout << RED << "Nothing in PhoneBook Go back" << RESET << std::endl;
		return ;
	}
	std::cout << YELLOW << "|     index| FirstName|  LastName|  NickName|" << RESET << std::endl;
	for(int index = 0; index < size; index++)
	{
		PhoneBook::PrintEntity(index);
		PhoneBook::PrintEntity(contact[index]._firstName);
		PhoneBook::PrintEntity(contact[index]._lastName);
		PhoneBook::PrintEntity(contact[index]._nickName);
		std::cout << "|" << std::endl;
	}

}

void	PhoneBook::PrintEntity(std::string context)
{
	char temp[10];
	int	space = context.length() > 10 ? 0 : 10 - context.length();
	if(space == 0)
		context.copy(temp, 9, 0);
	std::cout << "|";
	for(int i = 0; i < space; i++)
		std::cout << " " ;
	if(space == 0)
	{
		std::cout << temp << "." ;
	}
	else
		std::cout << context ;
	return ;
}

void	PhoneBook::PrintEntity(int context)
{
	std::cout << "|";
	for(int i = 0; i < 9; i++)
		std::cout << " " ;
	std::cout << context ;
	return ;
}
