/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:42:21 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/07 18:24:35 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"
#include "../inc/AForm.hpp"

#include <cstdlib>
#include <cctype>
#include <iostream>
#include <string>

static int digit(const char* str) {
    for (int i = 0; str[i]; i++) {
        if (!std::isdigit(str[i]))
            return 0;
    }
    return 1;
}

int main(int argc, char **argv) {
    std::string bName;
    int bGrade;
    std::string target;
    char option;
    

    if (argc >= 4 && digit(argv[2])) {
        bName = argv[1];
        bGrade = std::atoi(argv[2]);
        target = argv[3];
    }
    else {
    
        std::cout << "No se proporcionaron argumentos válidos.\nIngrese los datos de forma interactiva:" << std::endl;
        std::cout << "Bureaucrat name: ";
        std::cin >> bName;
        std::cout << "Bureaucrat grade (número entre 1 y 150): ";
        std::cin >> bGrade;
        std::cout << "Target for forms: ";
        std::cin >> target;
    }
    
    try
	{
		Bureaucrat original(bName, bGrade);
		std::cout << original << std::endl;
		Bureaucrat bShrubbery(original);
		Bureaucrat bRobot(original);
		Bureaucrat bPardon(original);
		ShrubberyCreationForm shrub(target);
		RobotomyRequestForm robot(target);
		PresidentialPardonForm pardon(target);
		std::cout << "\nEstado inicial de los formularios:\n" << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << shrub << std::endl;
		std::cout << robot << std::endl;
		std::cout << pardon << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "\n¿Desea firmar los formularios? (s/n): ";
		std::cin >> option;
		if (option == 's' || option == 'S')
		{
			bShrubbery.signForm(shrub);
			bRobot.signForm(robot);
			bPardon.signForm(pardon);
		}
		else
		{
			std::cout << "\nNo se firmaron los formularios." << std::endl;
		}
		std::cout << "\n¿Desea ejecutar los formularios? (s/n): ";
		std::cin >> option;
		if (option == 's' || option == 'S')
		{
			std::cout << std::endl << "-----------------------------------------" << std::endl;
			bShrubbery.executeForm(shrub);
			bRobot.executeForm(robot);
			bPardon.executeForm(pardon);
			std::cout << "-----------------------------------------" << std::endl;
		}
		else
		{
			std::cout << "\nNo se ejecutaron los formularios." << std::endl;
		}
        
    
        Intern someIntern;
        std::cout << "\nEjemplo de Intern:" << std::endl;
        AForm* form = someIntern.makeForm("robotomy request", target);
        if (form) {
        
            original.signForm(*form);
            original.executeForm(*form);
            delete form;
        }
    }
    catch (const std::exception & e) {
        std::cerr << "\nException caught: " << e.what() << std::endl;
    }
    
    return 0;
}
