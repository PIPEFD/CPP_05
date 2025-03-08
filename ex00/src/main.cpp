/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:07:14 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/08 01:01:18 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include <ctype.h>
#include <cstdlib>

static int	digit(char *digit)
{
	for (int i = 0; digit[i]; i++)
	{
		if (digit[i] >= '0' && digit[i] <= '9')
		{
			return (1);
		}
	}
	return (0);
}
int	main(int argc, char **argv)
{
	if (argc >= 2 && digit(argv[2]))
	{
		try
		{
			Bureaucrat a(argv[1], atoi(argv[2]));
			a.decrementGrade();
			a.incrementGrade();
			std::cout << a << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	else
		std::cout << " Argument not valid: ./Bureaucrat [Name] [Grade]" << std::endl;
	return (0);
}