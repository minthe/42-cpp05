/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:01:47 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/08 20:59:50 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include "AForm.class.hpp"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		~Bureaucrat();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, const int grade);

		std::string	getName() const;
		int			getGrade() const;
		void		incGrade();
		void		decGrade();
		void		signForm(AForm& form);
		void		executeForm(AForm const & form);

	private:
		const std::string	_name;
		int					_grade;
		int					_setGrade(const int grade);
};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& rhs);
