/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:04:49 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/08 13:29:57 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "../includes/Bureaucrat.class.hpp"

int	main()
{
	Bureaucrat* bob = new Bureaucrat("Bob", 1);
	std::cout << *bob << std::endl;

	try
	{
		Bureaucrat foo("Foo", 151);
		bob->incGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "after \"incGrade\": " << *bob << std::endl;
	
	// try
	// {
	// 	bob->decGrade();
	// }
	// catch (Bureaucrat::GradeTooLowException& ex)
	// {
	// 	std::cerr << "Exception caught: " << ex.what() << std::endl;
	// }

	// std::cout << "after \"decGrade\": " << *bob << std::endl;

	delete bob;
	return 0;
}
