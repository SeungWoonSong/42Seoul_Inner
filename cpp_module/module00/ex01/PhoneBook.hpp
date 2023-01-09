/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:18:59 by susong            #+#    #+#             */
/*   Updated: 2023/01/09 13:31:59 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __PHONEBOOK_HPP_
#define __PHONEBOOK_HPP_

#include <iostream>
#include <string>

#define RED      "\x1b[31m"
#define GREEN    "\x1b[32m"
#define YELLOW   "\x1b[33m"
#define BLUE     "\x1b[34m"
#define RESET    "\x1b[0m"

class PhoneBook
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
		static	int	count;
		static	int	full;

		void		putData(std::string dataType, std::string &dest);


	public:
		static	int		getCount();
		static	void	indexReset();
		static	void	indexPlus();
		static	void	addContact(PhoneBook &contact);
		static	void	showSearch(PhoneBook *contact);
		static	void	PrintEntity(std::string context);
		static	void	PrintEntity(int context);

		PhoneBook();
		~PhoneBook();

};

#endif
