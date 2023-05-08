/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:39:45 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/08 11:33:06 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.class.hpp"

// CONSTRUCTORS

Form::Form() : _name("default Form"), _signed(false), _grade_sign(0), _grade_exe(0) {}
Form::~Form() {}

Form& Form::operator=(const Form& rhs)
{
	if (this != &rhs)
	{
		_exception_handling(rhs.getGradeSign(), rhs.getGradeExe());
	}
	return *this;
}

Form::Form(const Form& src) : _name(src.getName()), _grade_sign(src.getGradeSign()), _grade_exe(src.getGradeExe())
{
	*this = src;
}

Form::Form(const std::string name) : _name(name), _grade_sign(0), _grade_exe(0) {}
Form::Form(const std::string name, const int grade_sign, const int grade_exe) : _name(name), _grade_sign(0), _grade_exe(0)
{
	_exception_handling(grade_sign, grade_exe);
}

// FUNCTIONS

void	Form::_exception_handling(const int grade_sign, const int grade_exe)
{
	try
	{
		if (grade_sign < 1 || grade_exe < 1 )
			throw Form::GradeTooHighException();
	}
	catch (Form::GradeTooHighException& ex)
	{
		std::cerr << "Exception caught: " << ex.what() << std::endl;
		return ;
	}

	try
	{
		if (grade_sign > 150 || grade_exe > 150)
			throw Form::GradeTooLowException();
	}
	catch (Form::GradeTooLowException& ex)
	{
		std::cerr << "Exception caught: " << ex.what() << std::endl;
		return ;
	}
}

void	Form::beSigned()
{
	// TODO
}

// OVERLOADS

std::ostream & operator<<(std::ostream & o, const Form& rhs)
{
	o << "Form: " << rhs.getName() << ", signed: " << rhs.getSigned() << ", grade_sign: " << rhs.getGradeSign() << ", grade_exe: " << rhs.getGradeExe();
	return (o);
}
