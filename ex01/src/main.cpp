/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:50:27 by pipe              #+#    #+#             */
/*   Updated: 2025/03/07 17:52:06 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
#include <ctype.h>
#include <stdlib.h>

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
	if (argc >= 6 && digit(argv[2]) && digit(argv[4]) && digit(argv[5]))
	{
		try
		{
			Bureaucrat b(argv[1], std::atoi(argv[2]));
			Form contract(argv[3], std::atoi(argv[4]), std::atoi(argv[5]));
			b.signForm(contract);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	else
	{
		std::cout << "Argument not valid: ./program [BureaucratName] [BureaucratGrade] [FormName] [GradeToSign] [GradeToExecute]" << std::endl;
	}
	return (0);
}
