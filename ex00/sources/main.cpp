/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:04:49 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/07 11:07:04 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

int	main()
{
	try
	{
		int i = 1;
		if (i > 0)
			throw std::exception() ;
	}
	catch (std::exception &exception)
	{
		
	}
}
