/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:04:49 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/07 18:29:48 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "../includes/Bureaucrat.class.hpp"

int	main()
{
	Bureaucrat* bob = new Bureaucrat("Bob");

	std::cout << bob->getName() << std::endl;
	try
	{
		bob->incGrade();
		if (i > 0) // TODO how to test if the class has an exception?
			throw std::exception() ;
	}
	catch (std::exception e)
	{
		
	}
	delete bob;
	return 0;
}
