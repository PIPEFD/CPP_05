/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pipe <pipe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:25:59 by pipe              #+#    #+#             */
/*   Updated: 2025/03/04 21:26:00 by pipe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

=======
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 01:59:57 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/06 04:14:49 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"
#include <fstream>
#include <cstdlib>


RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "Presidential Constructor To Default" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target)
{
    std::cout << " Copy Presidential Constructor To Default" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
    }
    return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Presidential Destroyer To Default" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    checkExecution(executor);
    std::cout << "Bzzzz... drilling noises..." << std::endl;
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << "." << std::endl;
}
>>>>>>> 9956512 (changes)
