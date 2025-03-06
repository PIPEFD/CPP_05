/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pipe <pipe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:59:49 by pipe              #+#    #+#             */
/*   Updated: 2025/03/04 21:00:49 by pipe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <AForm.hpp>
#include <string>


class ShrubberyCreationForm : public AForm
{
    private:
        const std::string _target;
    public:
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
        ~ShrubberyCreationForm();
        
=======
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:24:32 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/06 02:19:05 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP

#define SHRUBBERYCREATIONFORM_HPP

#include "../inc/AForm.hpp"

#include <string>

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string _target;
	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
		virtual ~ShrubberyCreationForm();

		virtual void execute(Bureaucrat const &executor) const;
>>>>>>> 9956512 (changes)
};

#endif