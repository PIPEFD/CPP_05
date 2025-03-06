/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pipe <pipe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:43:49 by pipe              #+#    #+#             */
/*   Updated: 2025/03/02 21:43:51 by pipe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

=======
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:27:59 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/06 03:59:40 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

#include <cstdlib>
#include <cctype>
#include <iostream>
#include <string>

int main() {
    std::string bName;
    int bGrade;
    std::string target;
    char option;

    // Solicitar datos interactivos
    std::cout << "Ingrese los datos del Bureaucrat:" << std::endl;
    std::cout << "Nombre: ";
    std::cin >> bName;
    std::cout << "Grado (número entre 1 y 150): ";
    std::cin >> bGrade;
    std::cout << "Target para los formularios: ";
    std::cin >> target;
    
    try {
        // Creación del Bureaucrat original
        Bureaucrat original(bName, bGrade);
        std::cout << "\nBureaucrat creado:\n" << original << std::endl;
        
        // Se crean copias del Bureaucrat para asignarlas a cada formulario.
        Bureaucrat bShrubbery(original);
        Bureaucrat bRobot(original);
        Bureaucrat bPardon(original);
        
        // Creación de los tres formularios concretos con el target proporcionado.
        ShrubberyCreationForm shrub(target);
        RobotomyRequestForm robot(target);
        PresidentialPardonForm pardon(target);
        
        // Mostrar el estado inicial de cada formulario.
        std::cout << "\nEstado inicial de los formularios:" << std::endl;
        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;
        
        // Preguntar si se desea firmar los formularios.
        std::cout << "\n¿Desea firmar los formularios? (s/n): ";
        std::cin >> option;
        if (option == 's' || option == 'S') {
            bShrubbery.signForm(shrub);
            bRobot.signForm(robot);
            bPardon.signForm(pardon);
            
            std::cout << "\nEstado de los formularios tras la firma:" << std::endl;
            std::cout << shrub << std::endl;
            std::cout << robot << std::endl;
            std::cout << pardon << std::endl;
        }
        else {
            std::cout << "\nNo se firmaron los formularios." << std::endl;
        }
        
        // Preguntar si se desea ejecutar los formularios.
        std::cout << "\n¿Desea ejecutar los formularios? (s/n): ";
        std::cin >> option;
        if (option == 's' || option == 'S') {
            // Cada copia del Bureaucrat intenta ejecutar su formulario asignado.
            bShrubbery.executeForm(shrub);
            bRobot.executeForm(robot);
            bPardon.executeForm(pardon);
        }
        else {
            std::cout << "\nNo se ejecutaron los formularios." << std::endl;
        }
    }
    catch (const std::exception & e) {
        std::cerr << "\nException caught: " << e.what() << std::endl;
    }
    
    return 0;
}
>>>>>>> 9956512 (changes)
