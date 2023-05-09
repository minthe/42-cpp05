/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:39:45 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/09 10:00:21 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.class.hpp"

// CONSTRUCTORS

AForm::AForm() : _name("default AForm"), _signed(false), _grade_sign(150), _grade_exe(150) {}
AForm::AForm(const std::string name) : _name(name), _signed(false), _grade_sign(150), _grade_exe(150) {}
AForm::AForm(const std::string name, const int grade_sign, const int grade_exe) : _name(name), _signed(false), _grade_sign(this->setGrade(grade_sign)), _grade_exe(this->setGrade(grade_exe)) {}
AForm::~AForm() {}

AForm::AForm(const AForm& src) : _name(src.getName()), _signed(src.getSigned()), _grade_sign(src.getGradeSign()), _grade_exe(src.getGradeExe())
{
	*this = src;
}

AForm& AForm::operator=(const AForm& rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	return *this;
}

// FUNCTIONS

std::string AForm::getName() const
{
	return _name;
}

bool	AForm::getSigned() const
{
	return _signed;
}

int		AForm::getGradeSign() const
{
	return _grade_sign;
}

int		AForm::getGradeExe() const
{
	return _grade_exe;
}

void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _grade_sign)
	{
		throw AForm::GradeTooLowException();
		return ;
	}
	_signed = true;
}

int		AForm::setGrade(const int grade)
{
	if (grade > 0 && grade < 151)
		return grade;
	else if (grade < 1)
		throw AForm::GradeTooHighException();
	else if (grade > 150)
		throw AForm::GradeTooLowException();
	return 150;
}

void	AForm::setSigned(bool s)
{
	_signed = s;
}

// EXCEPTIONS

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("\x1b[31mGrade too high exception\x1b[0m");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("\x1b[31mGrade too low exception\x1b[0m");
}

const char* AForm::FormNotSigned::what() const throw()
{
	return ("\x1b[31mForm not signed\x1b[0m");
}

// OVERLOADS

std::ostream & operator<<(std::ostream & o, const AForm& rhs)
{
	o << "AForm: " << rhs.getName() << ", signed: " << rhs.getSigned() << ", grade_sign: " << rhs.getGradeSign() << ", grade_exe: " << rhs.getGradeExe();
	return (o);
}
