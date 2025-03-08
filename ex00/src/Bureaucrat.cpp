/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:37:59 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/08 01:00:27 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"


Bureaucrat::Bureaucrat()
{
	std::cout << "Constructor to defatult" << std::endl;
    
}
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name),
	_grade(other._grade)
{
	std::cout << "Copy of Constructor to defatult" << std::endl;
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
	std::cout << "Desctructed of Boureaucrat" << std::endl;
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

const std::string &Bureaucrat::getName() const
{
	return (_name);
}

void Bureaucrat::incrementGrade()
{
	if (getGrade() <= 1)
	{
		throw GradeTooHighException();
	}
	_grade--;
}
void Bureaucrat::decrementGrade()
{
	if (getGrade() >= 150)
	{
		throw GradeTooLowException();
	}
	_grade++;
}
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade to high for Bureaucrat");
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade to low for Bureaucrat");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}