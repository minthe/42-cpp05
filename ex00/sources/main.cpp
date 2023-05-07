/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:04:49 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/07 19:31:31 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "../includes/Bureaucrat.class.hpp"

int	main()
{
	Bureaucrat* bob = new Bureaucrat("Bob", -15);
	std::cout << *bob << std::endl;

	try
	{
		bob->incGrade();
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "\x1b[31mGradeTooHighException\x1b[0m" << std::endl;
	}

	std::cout << "after \"incGrade\": " << *bob << std::endl;
	
	try
	{
		bob->decGrade();
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "\x1b[31mGradeTooLowException\x1b[0m" << std::endl;
	}

	std::cout << "after \"decGrade\": " << *bob << std::endl;

	delete bob;
	return 0;
}
