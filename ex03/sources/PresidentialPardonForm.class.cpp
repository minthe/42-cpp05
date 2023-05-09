/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.class.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:49:23 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/09 13:40:26 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/PresidentialPardonForm.class.hpp"


PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5) , _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src.getName(), 25, 5)
{
	this->setSigned(src.getSigned());
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	if (this != &rhs)
	{
		this->setSigned(rhs.getSigned());
	}
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
	{
		throw FormNotSigned();
		return ;
	}
	if (executor.getGrade() > this->getGradeExe())
	{
		throw GradeTooLowException();
		return ;
	}
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
