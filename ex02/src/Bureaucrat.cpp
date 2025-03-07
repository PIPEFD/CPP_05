/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 01:20:03 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/07 01:20:04 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"


Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
    std::cout << "Bureaucrat to default" << std::endl;

    if (grade < 1)
        throw GradeToHighException();
    else if (grade > 150)
        throw GradeToHighException();
    grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
    std::cout << " Copy Constructor" << std::endl;
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
    std::cout << "Destroyer To Bureaucrat" << std::endl;
}

const std::string &Bureaucrat::getName() const
{
    return (_name);    
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

const char *Bureaucrat::GradeToHighException:: what() const throw()
{
    return ("Grade To High");
}


const char *Bureaucrat::GradeToLowException:: what() const throw()
{
    return ("Grade To Low");
}

void Bureaucrat::signForm(AForm &f) const
{
    try {
        f.beSigned(*this);
        std::cout << _name << " signed " << f << std::endl;
    }
    catch (std::exception & e) {
        std::cout << _name << " couldn’t sign " << f << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << _name << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (os);
}






