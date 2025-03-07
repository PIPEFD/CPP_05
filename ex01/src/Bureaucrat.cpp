/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:37:27 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/07 17:44:09 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"



Bureaucrat::Bureaucrat(const std::string &name, int gradee) :  name(name)
{
    if (gradee < 1)
        throw GradeToHighException();
    else if (gradee > 150)
        throw GradeToLowException();
    grade = gradee;
}


Bureaucrat::Bureaucrat(const Bureaucrat &other) :  name(other.name), grade(other.grade)
{
    
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
    std::cout << "Destructor of Bureaucrat" << std::endl;
}
const std::string &Bureaucrat::getName() const
{
    return (name);    
}


int Bureaucrat::getGrade() const
{
    return (grade);
}

void Bureaucrat::incrementGrade()
{
    if (getGrade() <= 1)
        throw GradeToHighException();
    grade--;

}


void Bureaucrat::decrementGrade()
{
    if (getGrade() >= 150)
        throw GradeToLowException();
    grade++;
}

const char*  Bureaucrat::GradeToHighException::what() const throw()
{
	return ("Grade to high for Bureaucrat");
}

const char* Bureaucrat::GradeToLowException::what() const throw()
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
        std::cout << name <<  " with grade " << getGrade() << " signed " << form << std::endl;
    }
    catch (std::exception & e) {
        std::cout << name << " couldn’t sign " << form << " because " << std::endl << e.what() << std::endl;
    }
}