/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.class.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:29:10 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/09 09:51:38 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/RobotomyRequestForm.class.hpp"


RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src.getName(), 72, 45)
{
	this->setSigned(src.getSigned());
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	if (this != &rhs)
	{
		this->setSigned(rhs.getSigned());
	}
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
	{
		throw FormNotSigned();
		return ;
	}
	else if (executor.getGrade() > this->getGradeExe())
	{
		throw GradeTooLowException();
		return ;
	}
	std::cout << "Thrilling Noise" << std::endl;
	std::time_t currentTime = std::time(0);
	if (currentTime % 2 == 0)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << "robotomy on " << _target << " failed" << std::endl;
}
