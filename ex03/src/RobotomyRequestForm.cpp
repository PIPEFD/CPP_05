/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 01:18:55 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/07 17:15:42 by dbonilla         ###   ########.fr       */
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
    std::cout << "Roboto Destroyer To Default" << std::endl;
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
