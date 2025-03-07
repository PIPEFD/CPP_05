/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 01:03:54 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/07 16:10:15 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP

#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>





class AForm;
class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &rhs);
        ~Bureaucrat();

        const std::string &getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();
        int getValueToExecute() const;
        int getValiueToSigned() const;
        bool isSigned() const;

        void signForm(AForm &f);
        void executeForm(AForm const &form);

        class ExceptionToHighGrade : public::std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class ExceptionToLowGrade : public::std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &f);

#endif
