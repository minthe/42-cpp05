/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:40:11 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/08 23:34:23 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.class.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const AForm& src);
		AForm& operator=(const AForm& rhs);
		virtual ~AForm();

		AForm(const std::string name);
		AForm(const std::string name, const int grade_sign, const int grade_exe);

		class GradeTooHighException : public std::exception // TODO is it possible to link this?
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class FormNotSigned : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		std::string		getName() const;
		bool			getSigned() const;
		int				getGradeSign() const;
		int				getGradeExe() const;
		int				setGrade(const int grade);
		void			setSigned(bool s);
		void			beSigned(Bureaucrat& bureaucrat);
		virtual void	execute(Bureaucrat const & executor) const = 0;

	private:
		const std::string	_name;
		bool				_signed;
		const int			_grade_sign;
		const int			_grade_exe;
};

std::ostream&	operator<<(std::ostream& o, const AForm& rhs);
