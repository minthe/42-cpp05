/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:01:47 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/08 11:32:10 by vfuhlenb         ###   ########.fr       */
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
		Bureaucrat(const std::string name, const int grade);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("\x1b[31mGrade too high exception\x1b[0m");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("\x1b[31mGrade too low exception\x1b[0m");
				}
		};

		std::string	getName() const;
		int			getGrade() const;
		void		incGrade();
		void		decGrade();
		void		signForm();

	private:
		const std::string	_name;
		int					_grade;
		void				_exception_handling(const int grade);

};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& rhs);
