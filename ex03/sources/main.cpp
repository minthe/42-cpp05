/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:36:00 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/09 10:40:00 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "../includes/Bureaucrat.class.hpp"
#include "../includes/ShrubberyCreationForm.class.hpp"
#include "../includes/RobotomyRequestForm.class.hpp"
#include "../includes/PresidentialPardonForm.class.hpp"
#include "../includes/Intern.class.hpp"

int	main()
{
	{
		std::cout << "\nTEST 1 shrubbery\n" << std::endl;
		try
		{
			Bureaucrat bob("Bob", 137);
			// bob.decGrade();
			ShrubberyCreationForm shrubbery("Shrubbery");
			ShrubberyCreationForm shrubbery2("home");
			bob.signForm(shrubbery2);
			shrubbery2 = shrubbery;
			bob.executeForm(shrubbery2);
		}
		catch (std::exception& e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "\nTEST 2 robotomy\n" << std::endl;
		try
		{
			Bureaucrat bob("Bob", 45);
			// bob.decGrade();
			RobotomyRequestForm robotomy("home");
			RobotomyRequestForm robotomy2("home");
			bob.signForm(robotomy2);
			// shrubbery2 = robotomy;
			bob.executeForm(robotomy2);
		}
		catch (std::exception& e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "\nTEST 3 PresidentialPardonForm\n" << std::endl;
		try
		{
			Bureaucrat bob("Bob", 7);
			// bob.decGrade();
			PresidentialPardonForm pardon("home");
			PresidentialPardonForm pardon2("home");
			bob.signForm(pardon2);
			// pardon2 = pardon;
			bob.executeForm(pardon2);
		}
		catch (std::exception& e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "\nTEST 4 Intern\n" << std::endl;
		PresidentialPardonForm* president = new PresidentialPardonForm("new");
		Intern	someRandomIntern;
		AForm*	rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		try
		{
			Bureaucrat bob("Bob", 150);
			bob.signForm(*rrf);
			bob.executeForm(*rrf);
		}
		catch (std::exception& e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		delete rrf;
		delete president;
		try
		{
			Bureaucrat* bur = new Bureaucrat("bur", 100);
			std::cout << *bur << std::endl;
			delete bur;
		}
		catch (std::exception& e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	return 0;
}
