/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:02:57 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/08 01:17:02 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

AForm::AForm(const std::string &name, int gradeToExcecution,
	int gradeToSigned) : _name(name), _gradeToExcecution(gradeToExcecution),
	_gradeToSigned(gradeToSigned), _isSigned(false)
{
	if (gradeToExcecution < 1 || gradeToSigned < 1)
		throw GradeTooHighException();
	else if (gradeToExcecution > 150 || gradeToSigned > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name),
	_gradeToExcecution(other._gradeToExcecution),
	_gradeToSigned(other._gradeToSigned)
{
	std::cout << "Copy of Constructor" << std::endl;
}

AForm &AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
	{
		_isSigned = rhs._isSigned;
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << "Destroyer Abstract Class" << std::endl;
}

const std::string &AForm::getName() const
{
	return (_name);
}

int AForm::getGradeToExcecute() const
{
	return (_gradeToExcecution);
}

int AForm::getGradeToSigned() const
{
	return (_gradeToSigned);
}

bool AForm::isSigned() const
{
	return (_isSigned);
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSigned)
		throw GradeTooLowException();
	_isSigned = true;
}

void AForm::checkExecution(Bureaucrat const &executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExcecution)
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade to High for signed");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade to Low for signed");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("AForm is not signed");
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << "AForm \"" << f.getName() << "\" [signed: " << (f.isSigned() ? "yes" : "no") << ",grade required to sign: " << f.getGradeToSigned() << ",grade required to execute: " << f.getGradeToExcecute() << "]";
	return (os);
}
