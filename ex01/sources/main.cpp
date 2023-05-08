/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:36:00 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/08 17:00:37 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "../includes/Bureaucrat.class.hpp"
#include "../includes/Form.class.hpp"

int	main()
{
	{
		std::cout << "\nTEST 1\n" << std::endl;
		try
		{
			Bureaucrat bob("Bob1", 666);
			Form form("Form1", 50, 50);
			std::cout << bob << std::endl;
			std::cout << form << std::endl;
			bob.signForm(form);
			std::cout << "after \"incGrade\": " << bob << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "\nTEST 2\n" << std::endl;
		try
		{
			Bureaucrat bob("Bob1", 100);
			Form form("Form1", 50, 50);
			std::cout << bob << std::endl;
			std::cout << form << std::endl;
			bob.signForm(form);
			std::cout << "after \"incGrade\": " << bob << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	return 0;
}
