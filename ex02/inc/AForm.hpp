/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipe <pipe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:43:45 by pipe              #+#    #+#             */
/*   Updated: 2025/03/04 20:44:44 by pipe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP

#define AFORM_HPP
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;


class AForm
{
    private:
        const std::string _name;
        const int _gradeToSigned;
        const int _gradeToExecute;
        bool _isSigned;
    
    protected:
        void checkExecution(const Bureaucrat &executor);
        
    public:
        AForm(const std::string &name, int gradeToSigned, int _gradeToExecute);
        AForm(const AForm &other);
        AForm &operator=(const AForm &rhs);
        ~AForm();
        
        const std::string &getName() const;
        int getGradeToSigned() const;
        int getGradeToExecute() const;
        bool isSigned() const;

        void beSigned(const Bureaucrat &b);

        class GradeToHighExecption : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };
        
        class GradeToLowExecption : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };
};

std::ostream &operator<<(std::ostream os, const Form &f);

#endif
