/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:36:00 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/08 15:32:35 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "../includes/Bureaucrat.class.hpp"
#include "../includes/Form.class.hpp"

int	main()
{
	try
	{
		Bureaucrat bob("Bob1", 1);
		Form form("Form1", 50, 50);
		std::cout << bob << std::endl;
		std::cout << form << std::endl;
		bob.signForm(form);
		std::cout << "after \"incGrade\": " << bob << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
		
	try
	{
		Bureaucrat bob("Bob1", 100);
		Form form("Form1", 50, 50);
		std::cout << bob << std::endl;
		std::cout << form << std::endl;
		bob.signForm(form);
		std::cout << "after \"incGrade\": " << bob << std::endl;
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
		

	return 0;
}
