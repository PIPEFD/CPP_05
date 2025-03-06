/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipe <pipe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:37:27 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/04 17:54:27 by pipe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"



Bureaucrat::Bureaucrat(const std::string &name, int gradee) :  name(name)
{
    // std::cout << "Constructor to default" << std::endl;
    if (gradee < 1)
        throw GradeToHighException();
    else if (gradee > 150)
        throw GradeToLowException();
    grade = gradee;
}


Bureaucrat::Bureaucrat(const Bureaucrat &other) :  name(other.name), grade(other.grade)
{
    // std::cout << "Copy Constructor to Default" << std::endl;
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
    // std::cout << "Destructor for Defult" << std::endl;
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
    std::cout<< grade << std::endl; /* Grade after increment*/

}


void Bureaucrat::decrementGrade()
{
    if (getGrade() >= 150)
        throw GradeToLowException();
    grade++;
    // std::cout<< grade << std::endl; /* Grade after decrement*/   
}

const char*  Bureaucrat::GradeToHighException::what() const throw()
{
    return ("Grade to high");
}

const char* Bureaucrat::GradeToLowException::what() const throw()
{
    return ("Grade to low............");
}
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    (void) b;
    // os << b.getName() << ", Bureaucrat Grade   "  << b.getGrade();
    return (os);
}
void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << name <<  " with grade " << getGrade() << " signed " << form << std::endl;
    }
    catch (std::exception & e) {
        std::cout << name << " couldn’t sign " << form << " because " << e.what() << std::endl;
    }
}