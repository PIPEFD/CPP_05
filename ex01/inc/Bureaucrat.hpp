/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipe <pipe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:37:31 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/04 00:47:03 by pipe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    
    public:
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &rhs);
        ~Bureaucrat();


        const std::string &getName() const;
        int getGrade() const;
        
        void incrementGrade();
        void decrementGrade();

        void signForm(Form & form);


        class GradeToHighException : public std::exception
        {
            public:
               virtual const char*  what() const throw();
        };

        class GradeToLowException :  public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif