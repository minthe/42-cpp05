/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:36:00 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/08 11:05:57 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "../includes/Bureaucrat.class.hpp"
#include "../includes/Form.class.hpp"

int	main()
{
	Bureaucrat* bob = new Bureaucrat("Bob", -15);
	std::cout << *bob << std::endl;

	try
	{
		bob->incGrade();
	}
	catch (Bureaucrat::GradeTooHighException& ex)
	{
		std::cerr << "Exception caught: " << ex.what() << std::endl;
	}

	std::cout << "after \"incGrade\": " << *bob << std::endl;
	
	try
	{
		bob->decGrade();
	}
	catch (Bureaucrat::GradeTooLowException& ex)
	{
		std::cerr << "Exception caught: " << ex.what() << std::endl;
	}

	std::cout << "after \"decGrade\": " << *bob << std::endl;

	delete bob;
	return 0;
}
