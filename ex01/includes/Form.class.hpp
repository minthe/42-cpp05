/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:40:11 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/08 12:38:12 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

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

		class GradeTooHighException : public std::exception // TODO is it possible to link this?
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
		bool		getSigned() const;
		int			getGradeSign() const;
		int			getGradeExe() const;
		void		beSigned(Bureaucrat&);

	private:
		const std::string	_name;
		bool				_signed;
		const int			_grade_sign;
		const int			_grade_exe;
		void				_exception_handling(const int grade_sign, const int grade_exe);

};

std::ostream&	operator<<(std::ostream& o, const Form& rhs);
