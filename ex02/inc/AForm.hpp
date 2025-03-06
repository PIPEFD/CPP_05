/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pipe <pipe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:43:45 by pipe              #+#    #+#             */
/*   Updated: 2025/03/04 20:44:44 by pipe             ###   ########.fr       */
=======
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:13:15 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/06 04:10:50 by dbonilla         ###   ########.fr       */
>>>>>>> 9956512 (changes)
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP

#define AFORM_HPP
<<<<<<< HEAD
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
=======

#include <iostream>
#include <string>
#include <exception>
#include "../inc/Bureaucrat.hpp"


class Bureaucrat;

class AForm
{
    private:
        const   std::string _name;
        const   int _gradeToExcecution;
        const   int _gradeToSigned;
        bool    _isSigned;

    protected:
            void checkExecution(Bureaucrat const &executor) const;
    public:
        AForm(const std::string &name, int gradeToExcecution, int gradeToSigned);
        AForm(const AForm &rhs);
        AForm &operator=(const AForm &other);
        virtual ~AForm();
        
        const std::string &getName() const;
        int getGradeToExcecute() const;
        int getGradeToSigned() const;
        bool isSigned() const;

        void beSigned(const Bureaucrat &b);
        virtual void execute(Bureaucrat const & executor) const = 0;

        class GradeToHighException : public std::exception
>>>>>>> 9956512 (changes)
        {
            public:
                virtual const char * what() const throw();
        };
<<<<<<< HEAD
        
        class GradeToLowExecption : public std::exception
=======

        class GradeToLowException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };

        class FormNotSignedException : public std::exception
>>>>>>> 9956512 (changes)
        {
            public:
                virtual const char * what() const throw();
        };
};

<<<<<<< HEAD
std::ostream &operator<<(std::ostream os, const Form &f);

#endif
=======
std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif
>>>>>>> 9956512 (changes)
