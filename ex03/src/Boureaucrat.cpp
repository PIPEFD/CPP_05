/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boureaucrat.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 01:03:34 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/07 18:32:01 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"


Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name),_grade(grade)
{
    if (grade < 1)
        throw ExceptionToHighGrade();
    else if (grade > 150)
        throw ExceptionToLowGrade();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
    
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
    if(this != &rhs)
    {
        _grade = rhs._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destroyer of Bureaucrat" << std::endl;

}
void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw ExceptionToHighGrade();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw ExceptionToLowGrade();
    _grade++;
}

const std::string &Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

void Bureaucrat::signForm(AForm &f)
{
    try
    {
        f.beSigned(*this);
        std::cout << _name << " signed " << f.getName() << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cout << _name << " couldn’t sign " << f.getName() 
                  << " because " << e.what() << std::endl;
    }
    
}

void Bureaucrat::executeForm(AForm const &form)
{
    try 
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception & e) 
    {
        std::cout << _name << " couldn't execute " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

const char * Bureaucrat::ExceptionToHighGrade::what() const throw()
{
    return ("Grade To High");
}

const char * Bureaucrat::ExceptionToLowGrade::what() const throw()
{
    return ("Grade To Low");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    (void) os;
    (void) b;
    return(os);
}



