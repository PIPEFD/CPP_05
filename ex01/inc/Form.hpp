/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:08:46 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/03 18:56:43 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>



class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
    
    public:
        Form(const std::string &name, int gradeToSign, int gradeToExecute);
        Form( const Form &other);
        Form &operator=(const Form &rhs);
        ~Form();


        const std::string &getName() const;
        const int getGradeToExecute() const;
        const int getGradeToSigned() const;
        bool isSigned();



        void beSigned(const Bureaucrat &b);

        class GradeToHighException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };
        
        class GradeToLowException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };

        
        
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif