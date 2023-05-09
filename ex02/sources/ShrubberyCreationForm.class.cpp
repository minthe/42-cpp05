/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.class.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:50:33 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/09 09:50:50 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.class.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src.getName(), 145, 137)
{
	this->setSigned(src.getSigned());
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this != &rhs)
	{
		this->setSigned(rhs.getSigned());
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
	filename = _target;
	filename.append("_shrubbery");
	std::ofstream file(filename);
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
