/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pipe <pipe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:43:40 by pipe              #+#    #+#             */
/*   Updated: 2025/03/04 19:29:45 by pipe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
=======
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:13:21 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/06 04:10:56 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUREAUCRAT_HPP
#define	BUREAUCRAT_HPP
>>>>>>> 9956512 (changes)

#include <iostream>
#include <string>
#include <exception>

<<<<<<< HEAD
class Form;

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
        void signForm(Form &form);

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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

=======
class AForm;

class Bureaucrat
{
	private:
		const	std::string	_name;
		int					_grade;
	public:
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &rhs);
		~Bureaucrat();

		const std::string &getName() const;
		int getGrade() const;
		
		void signForm(AForm &f) const;
        void executeForm(AForm const & form);

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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);
>>>>>>> 9956512 (changes)
#endif