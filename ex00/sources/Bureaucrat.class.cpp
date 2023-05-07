/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:31:40 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/07 11:16:28 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.class.hpp"

// CONSTRUCTORS

Bureaucrat::Bureaucrat() : _name("Bureaucrat") {}
Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
		_grade = rhs.getGrade();
	return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : Bureaucrat()
{
	*this = src;
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

void		Bureaucrat::incGrade() // TODO add exceptions
{
	if (_grade > 1)
		_grade--;
}

void		Bureaucrat::decGrade() // TODO add exceptions
{
	if (_grade < 150)
		_grade++;
}
