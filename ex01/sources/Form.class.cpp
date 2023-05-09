/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:39:45 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/09 12:05:09 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.class.hpp"

// CONSTRUCTORS

Form::Form() : _name("default Form"), _signed(false), _grade_sign(150), _grade_exe(150) {}
Form::Form(const std::string name) : _name(name), _signed(false), _grade_sign(150), _grade_exe(150) {}
Form::Form(const std::string name, const int grade_sign, const int grade_exe) : _name(name), _signed(false), _grade_sign(this->_setGrade(grade_sign)), _grade_exe(this->_setGrade(grade_exe)) {}
Form::~Form() {}

Form::Form(const Form& src) : _name(src.getName()), _signed(src.getSigned()), _grade_sign(src.getGradeSign()), _grade_exe(src.getGradeExe()) {}

Form& Form::operator=(const Form& rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	return *this;
}


// FUNCTIONS

std::string Form::getName() const
{
	return _name;
}

bool	Form::getSigned() const
{
	return _signed;
}

int		Form::getGradeSign() const
{
	return _grade_sign;
}

int		Form::getGradeExe() const
{
	return _grade_exe;
}

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _grade_sign)
	{
		throw Form::GradeTooLowException();
		return ;
	}
	_signed = true;
}

int		Form::_setGrade(const int grade)
{
	if (grade > 0 && grade < 151)
		return grade;
	else if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
	return 150;
}

// EXCEPTIONS

const char* Form::GradeTooHighException::what() const throw()
{
	return ("\x1b[31mGrade too high exception\x1b[0m");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("\x1b[31mGrade too low exception\x1b[0m");
}

// OVERLOADS

std::ostream & operator<<(std::ostream & o, const Form& rhs)
{
	o << "Form: " << rhs.getName() << ", signed: " << rhs.getSigned() << ", grade_sign: " << rhs.getGradeSign() << ", grade_exe: " << rhs.getGradeExe();
	return (o);
}
