/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pipe <pipe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:51:46 by pipe              #+#    #+#             */
/*   Updated: 2025/03/04 21:02:37 by pipe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP 

#define PRESIDENTIALPARDONFORM_HPP


#include <AForm.hpp>
#include <string>


class PresidentialPardonForm : public AForm
{
    private:
        const std::string _target;
    public:
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
        ~PresidentialPardonForm();
        
        virtual void execute(Bureaucrat const & executor) const;

=======
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:24:27 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/06 02:19:12 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP

#define PRESIDENTIALPARDONFORM_HPP

#include "../inc/AForm.hpp"

#include <string>

class PresidentialPardonForm : public AForm
{
	private:
		const std::string _target;
	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
		virtual ~PresidentialPardonForm();

		virtual void execute(Bureaucrat const &executor) const;
>>>>>>> 9956512 (changes)
};

#endif