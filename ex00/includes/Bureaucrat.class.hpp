/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:01:47 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/08 15:20:09 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		~Bureaucrat();

		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, const int grade);

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

		std::string			getName() const;
		int					getGrade() const;
		void				incGrade();
		void				decGrade();

	private:
		const std::string	_name;
		int					_grade;
		int					_setGrade(const int grade);

};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& rhs);
