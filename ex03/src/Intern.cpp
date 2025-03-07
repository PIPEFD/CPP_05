/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:33:26 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/07 16:13:00 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"

typedef AForm* (*FormCreator)(const std::string& target);

static AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

Intern::Intern()
{
    std::cout << "Intern Constructor To Default" << std::endl;
}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern &Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() 
{
    
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    struct FormMapping {
        std::string name;
        FormCreator creator;
    };

    const FormMapping forms[] = {
        {"shrubbery creation", createShrubbery},
        {"robotomy request", createRobotomy},
        {"presidential pardon", createPardon}
    };

    const int formCount = sizeof(forms) / sizeof(FormMapping);
    for (int i = 0; i < formCount; i++) {
        if (forms[i].name == formName) {
            AForm* form = forms[i].creator(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    std::cout << "Intern cannot create form because \"" << formName << "\" is unknown." << std::endl;
    return NULL;
}