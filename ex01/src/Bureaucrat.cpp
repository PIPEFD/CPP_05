/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:37:27 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/08 01:14:38 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) :  _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    grade = _grade;
}
    

Bureaucrat::Bureaucrat(const Bureaucrat &other) :  _name(other._name), _grade(other._grade)
{
    
}


Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
    if (this != &rhs)
    {
        _grade = rhs._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor of Bureaucrat" << std::endl;
}
const std::string &Bureaucrat::getName() const
{
    return (_name);    
}


int Bureaucrat::getGrade() const
{
    return (_grade);
}

void Bureaucrat::incrementGrade()
{
    if (getGrade() <= 1)
        throw GradeTooHighException();
    _grade--;

}


void Bureaucrat::decrementGrade()
{
    if (getGrade() >= 150)
        throw GradeTooLowException();
    _grade++;
}

const char*  Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade to high for Bureaucrat");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade to low for Bureaucrat");
}
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    (void) b;
    return (os);
}
void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << _name <<  " with grade " << getGrade() << " signed " << form << std::endl;
    }
    catch (std::exception & e) {
        std::cout << _name << " couldn’t sign " << form << " because " << std::endl << e.what() << std::endl;
    }
}