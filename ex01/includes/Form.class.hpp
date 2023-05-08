/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:40:11 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/08 16:42:33 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.class.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const Form& src);
		Form& operator=(const Form& rhs);
		~Form();

		Form(const std::string name);
		Form(const std::string name, const int grade_sign, const int grade_exe);

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

		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeSign() const;
		int			getGradeExe() const;
		void		beSigned(Bureaucrat& bureaucrat);

	private:
		const std::string	_name;
		bool				_signed;
		const int			_grade_sign;
		const int			_grade_exe;
		int					_setGrade(const int grade);
};

std::ostream&	operator<<(std::ostream& o, const Form& rhs);
