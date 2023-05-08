/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:31:40 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/08 11:32:36 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.class.hpp"

// CONSTRUCTORS

Bureaucrat::Bureaucrat() : _name("default Bureaucrat"), _grade(0) {}
Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
	{
		_exception_handling(rhs.getGrade());
		if (rhs.getGrade() > 0 && rhs.getGrade() < 151)
			_grade = rhs.getGrade();
	}
	return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade)
{
	*this = src;
}

Bureaucrat::Bureaucrat(const std::string name) : _name(name), _grade(0) {}
Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name)
{
	_exception_handling(grade);
}

// FUNCTIONS

std::string	Bureaucrat::getName() const
{
	return _name;
}

int			Bureaucrat::getGrade() const
{
	return _grade;
}

void		Bureaucrat::incGrade()
{
	if (_grade > 1)
		_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void		Bureaucrat::decGrade()
{
	if (_grade < 150)
		_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::_exception_handling(const int grade)
{
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
	}
	catch (Bureaucrat::GradeTooHighException& ex)
	{
		std::cerr << "Exception caught: " << ex.what() << "\x1b[35m -> Initiated with grade 1\x1b[0m" << std::endl;
		_grade = 1;
		return ;
	}

	try
	{
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (Bureaucrat::GradeTooLowException& ex)
	{
		std::cerr << "Exception caught: " << ex.what() << "\x1b[35m -> Initiated with grade 150\x1b[0m" << std::endl;
		_grade = 150;
		return ;
	}
}

void	Bureaucrat::signForm()
{
	 // TODO
}

// OVERLOADS

std::ostream & operator<<(std::ostream & o, const Bureaucrat& rhs) // TODO Overload not working
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (o);
}
