/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pipe <pipe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:01:35 by pipe              #+#    #+#             */
/*   Updated: 2025/03/04 21:01:36 by pipe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

=======
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:53:34 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/06 02:19:17 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"
#include <fstream>


PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "Presidential Constructor To Default" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target)
{
    std::cout << " Copy Presidential Constructor To Default" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
    }
    return(*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Presidential Destroyer To Default" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    checkExecution(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
>>>>>>> 9956512 (changes)
