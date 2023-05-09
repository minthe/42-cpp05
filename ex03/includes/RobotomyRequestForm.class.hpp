/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.class.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:36:22 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/08 22:35:49 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.class.hpp"
#include <ctime>


class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& src);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
		~RobotomyRequestForm();

		RobotomyRequestForm(std::string target);

		void	execute(Bureaucrat const & executor) const;
	
	private:
		std::string	_target;
};
