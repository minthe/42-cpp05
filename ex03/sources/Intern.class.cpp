/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:02:49 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/08 23:30:52 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.class.hpp"

Intern::Intern() {}
Intern::~Intern() {}

Intern::Intern(const Intern& src)
{
	(void)src;
}

Intern& Intern::operator=(const Intern& rhs)
{
	(void)rhs;
	return *this;
}

AForm* Intern::makeForm(std::string form, std::string target)
{
	std::string forms[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	for (int i = 0; i < 3; i++)
	{
		if (form == forms[i])
		{
			switch (i)
			{
				case 0:
					return (new PresidentialPardonForm(target));
				case 1:
					return (new RobotomyRequestForm(target));
				case 2:
					return (new ShrubberyCreationForm(target));
			}
		}
	}
	std::cerr << "form " << form << " not found" << std::endl;
	return 0;
}
