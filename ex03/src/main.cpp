/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:42:21 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/07 16:11:17 by dbonilla         ###   ########.fr       */
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

// Función que verifica que la cadena contenga solo dígitos.
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
    
    // Si se proporcionan al menos 4 argumentos y el grado es numérico, se usan esos valores.
    if (argc >= 4 && digit(argv[2])) {
        bName = argv[1];
        bGrade = std::atoi(argv[2]);
        target = argv[3];
    }
    else {
        // Modo interactivo: se solicitan los datos al usuario.
        std::cout << "No se proporcionaron argumentos válidos.\nIngrese los datos de forma interactiva:" << std::endl;
        std::cout << "Bureaucrat name: ";
        std::cin >> bName;
        std::cout << "Bureaucrat grade (número entre 1 y 150): ";
        std::cin >> bGrade;
        std::cout << "Target for forms: ";
        std::cin >> target;
    }
    
    try {
        // Creación del Bureaucrat original
        Bureaucrat original(bName, bGrade);
        std::cout << "\nBureaucrat original creado:\n" << original << std::endl;
        
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
        
        char option;
        // Preguntar al usuario si desea firmar los formularios.
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
        
        // Preguntar al usuario si desea ejecutar los formularios.
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
        
        // Ejemplo del Intern: crear un formulario dinámicamente.
        Intern someIntern;
        std::cout << "\nEjemplo de Intern:" << std::endl;
        AForm* form = someIntern.makeForm("robotomy request", target);
        if (form) {
            // El Bureaucrat original firma y ejecuta el formulario creado por el Intern.
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
