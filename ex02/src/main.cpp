/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:27:59 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/07 18:12:59 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>

int	main(void)
{
	int		bGrade;
	char	option;

	std::string bName;
	std::string target;
	std::cout << "Ingrese los datos del Bureaucrat:" << std::endl;
	std::cout << "Nombre: ";
	std::cin >> bName;
	std::cout << "Grado (número entre 1 y 150): ";
	std::cin >> bGrade;
	std::cout << "Target para los formularios: ";
	std::cin >> target;
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
	}
	catch (const std::exception &e)
	{
		std::cerr << "\nException caught: " << e.what() << std::endl;
	}
	return (0);
}
