/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.class.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:50:33 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/09 13:40:49 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.class.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src.getName(), 145, 137)
{
	this->setSigned(src.getSigned());
	this->_target = src._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this != &rhs)
	{
		this->setSigned(rhs.getSigned());
		this->_target = rhs._target;
	}
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
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
	std::string filename;
	filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (file.is_open())
	{
		file << "     /\\  \n";
		file << "    /  \\ \n";
		file << "   /    \\\n";
		file << "  /      \\\n";
		file << " /________\\\n";
		file << "     ||   \n";
		file << "     ||   \n";
		file.close();
	}
	else
		std::cout << "ascii tree can't be written to file" << std::endl;
}
