/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipe <pipe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:37:59 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/04 00:36:25 by pipe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int gradee): name(name)
{
    std::cout << "Constructor to defatult" << std::endl;
    if (gradee < 1)
        throw GradeToHighException();
    else if (gradee > 150)
        throw GradeToLowException();
    grade = gradee;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):  name(other.name), grade(other.grade)
{
    std::cout << "Copy of Constructor to defatult" << std::endl;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
    if (this != &rhs)
    {
        grade = rhs.grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Desctructed to Default" << std::endl;
}

int Bureaucrat::getGrade() const
{
    return (grade);
}      

const std::string &Bureaucrat::getName() const
{
    return (name);
}

void  Bureaucrat::incrementGrade()
{
    if (getGrade() <= 1)
    {
        throw GradeToHighException();
    }
    grade--;
    std::cout<< grade << std::endl; /* Grade after increment*/
}
void Bureaucrat::decrementGrade()
{
    if (getGrade() >=  150)
    {
        throw GradeToLowException();
    }
    grade++;
    std::cout<< grade << std::endl; /* Grade after decrement*/
}
const char* Bureaucrat::GradeToHighException::what() const throw()
{
    return ("Grade to high");
    
}
const char* Bureaucrat::GradeToLowException::what() const throw()
{
    return ("Grade to low");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (os);
}