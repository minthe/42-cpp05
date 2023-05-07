/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:04:49 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/07 12:31:43 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <iostream>
#include "../includes/Bureaucrat.class.hpp"

int	main()
{
	Bureaucrat* bob = new Bureaucrat("Bob");

	std::cout << bob->getName() << std::endl;
	// try
	// {
		
	// 	int i = 1;
	// 	if (i > 0)
	// 		throw std::exception() ;
	// }
	// catch (std::exception &exception)
	// {
		
	// }
	delete bob;
	return 0;
}
