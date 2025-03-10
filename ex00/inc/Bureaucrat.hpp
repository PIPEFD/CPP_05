/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:27:52 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/08 00:59:13 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>


class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &rhs);
        ~Bureaucrat();
        
        int getGrade () const;
        const std::string &getName() const;
        void incrementGrade();
        void decrementGrade();

        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char* what() const throw();
            
        };
        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };       
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif