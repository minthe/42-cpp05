/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:04:49 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/07 19:03:23 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "../includes/Bureaucrat.class.hpp"

int	main()
{
	Bureaucrat* bob = new Bureaucrat("Bob");
	std::cout << *bob << std::endl;
	std::cout << bob->getName() << std::endl;
	try
	{
		bob->decGrade();
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "handled" << std::endl;
	}
	
	delete bob;
	return 0;
}
