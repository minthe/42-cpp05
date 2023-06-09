/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:31:40 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/09 14:35:01 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.class.hpp"
#include <exception>

// CONSTRUCTORS

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150) {}
Bureaucrat::Bureaucrat(const std::string name) : _name(name), _grade(150) {}
Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name), _grade(this->_setGrade(grade)) {}
Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
		_grade = this->_setGrade(rhs.getGrade());
	return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src.getName()), _grade(this->_setGrade(src.getGrade())) {}

// FUNCTIONS

std::string	Bureaucrat::getName() const
{
	return _name;
}

int			Bureaucrat::getGrade() const
{
	return _grade;
}

int	Bureaucrat::_setGrade(const int grade)
{
	if (grade > 0 && grade < 151)
		return grade;
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return 150;
}

void		Bureaucrat::incGrade()
{
	if (_grade > 1)
		_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decGrade()
{
	if (_grade < 150)
		_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (const std::exception& e)
	{
		std::cout << "\x1b[31m" << _name << " couldn't sign '" << form.getName() << "' because \x1b[0m" << e.what() << std::endl;
		return ;
	}
	std::cout << _name << " signed " << form.getName() << std::endl;
	return ;
}

void	Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

// EXCEPTIONS

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("\x1b[31mGrade too high exception\x1b[0m");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("\x1b[31mGrade too low exception\x1b[0m");
}

// OVERLOADS

std::ostream & operator<<(std::ostream & o, const Bureaucrat& rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (o);
}
