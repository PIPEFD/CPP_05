/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 01:12:37 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/07 16:16:33 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>


#include "../inc/Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        int _valueToExecute;
        int _valueToSigned;
        bool _isSinged;
    protected:
        void checkExecution(Bureaucrat const &executor) const;
    public:
        AForm(const std::string &name, int valueToExecute, int valueToSigned);
        AForm(const AForm &other);
        AForm &operator=(const AForm &rhs);
        virtual ~AForm() = 0;
        // ~AForm();
        

        const std::string &getName() const;
        int getValueToExecute() const;
        int getValiueToSigned() const;
        bool isSigned() const;

        void beSigned(const Bureaucrat &b);
        virtual void execute(Bureaucrat const &executor) const = 0;

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

        class ExceptionNotSignedForm: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif