/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipe <pipe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:08:46 by dbonilla          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/04 17:00:50 by pipe             ###   ########.fr       */
=======
/*   Updated: 2025/03/05 17:13:10 by dbonilla         ###   ########.fr       */
>>>>>>> 9956512 (changes)
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
        int getGradeToExecute() const;
        int getGradeToSigned() const;
        bool isSigned() const;



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