/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pipe <pipe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:25:55 by pipe              #+#    #+#             */
/*   Updated: 2025/03/04 21:25:56 by pipe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

=======
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:00:31 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/06 02:19:22 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "Presidential Constructor To Default" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
    std::cout << " Copy Presidential Constructor To Default" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
    }
    return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Presidential Destroyer To Default" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    checkExecution(executor);
    std::ofstream ofs((_target + "_shrubbery").c_str());
    if (!ofs)
        return;
    ofs << "ASCII trees" << std::endl;
    ofs.close();
}
>>>>>>> 9956512 (changes)
