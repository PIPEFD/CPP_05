/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:07:14 by dbonilla          #+#    #+#             */
/*   Updated: 2025/02/28 11:18:48 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <stdlib.h>
#include <ctype.h>

static int digit (char *digit)
{
    for  (int i = 0; digit[i]; i++)
    {
        if (digit[i] >= '0' && digit[i] <= '9')
        {
            return (1);
        }
    }
    return (0);
}
int main (int argc, char **argv)
{
    // (void) argc;
    // (void) argv;
    if (argc >= 2 && digit(argv[2]))
    {
        try
        {
            Bureaucrat a (argv[1] , atoi(argv[2]));
            // std::cout << a << " Grade of Bureaucrat" << std::endl;
            std::cout << a.getGrade() << " Grade of Bureaucrat" << std::endl;
            std::cout << a.getName() << " Name of Bureaucrat" << std::endl;
            a.incrementGrade();
            std::cout << a.getGrade() << " Grade of Bureaucrat Increment" << std::endl;
            std::cout << a.getName() << " Name of Bureaucrat Increment " << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
        std::cout <<  " Argument not valid: ./Bureaucrat [Name] [Grade]" << std::endl;
    // try
    // {
    //     a.incrementGrade();
    //     a.incrementGrade();
    //     a.incrementGrade();
    //     a.incrementGrade();
        
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
    return (0); 
}