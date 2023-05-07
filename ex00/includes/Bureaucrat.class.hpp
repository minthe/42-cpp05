/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:01:47 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/07 18:54:03 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

		class GradeTooHighException : public std::exception // TODO is it ok to implement the virtual function here?
		{
			public:
				virtual const char* what() const throw()
				{
					return ("GradeTooHighException");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("GradeTooHighException");
				}
		};

		std::string	getName() const;
		int			getGrade() const;
		void		incGrade();
		void		decGrade();

	private:
		const std::string	_name;
		int					_grade;

};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& rhs);