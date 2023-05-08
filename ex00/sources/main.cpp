/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:04:49 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/08 17:02:37 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "../includes/Bureaucrat.class.hpp"

int	main()
{
	try
	{
		Bureaucrat bob("Bob1", 5);
		std::cout << bob << std::endl;
		bob.incGrade();
		std::cout << "after \"incGrade\": " << bob << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat bob("Bob2", 149);
		std::cout << bob << std::endl;
		bob.decGrade();
		std::cout << "after \"decGrade\": " << bob << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
