/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipe <pipe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:02:14 by pipe              #+#    #+#             */
/*   Updated: 2025/03/04 19:47:59 by pipe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw GradeToHighException();
    else if (grade > 150)
        throw GradeToLowException();

    _grade = grade;
}       
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
    
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
    if (this !=  &rhs)
        _name = rhs.name;
    return (*this);
}
Bureaucrat::~Bureaucrat()
{
    std::cout "Destroyed For Default" << std::endl;
    
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
    if (getGrade() < 1 )
        throw GradeToHighException();
    _grade++;
       
}
void Bureaucrat::decrementGrade()
{
    if (getGrade() > 150 )
        throw GradeToHighException();
    _grade--;
    
}
void Bureaucrat::signForm(Form &form) 
{
    try
    {
        /* code */
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
                
const char *Bureaucrat::GradeToHighException::what() const throw()
{
    return ("Grade To High");
}

const char *Bureaucrat::GradeToLowExecption:: what() const throw()
{
    return ("Grade To Low");
}

std::ostream &operator<<(const std::string name, int grade);

