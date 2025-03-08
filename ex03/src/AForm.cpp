/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:32:00 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/08 01:22:35 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

AForm::AForm(const std::string &name, int valueToExecute,
	int valueToSigned) : _name(name), _valueToExecute(valueToExecute),
	_valueToSigned(valueToSigned), _isSinged(false)
{
	if (valueToExecute < 1 || valueToSigned < 1)
		throw GradeTooHighException();
	else if (valueToExecute > 150 || valueToSigned > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name),
	_valueToExecute(other._valueToExecute),
	_valueToSigned(other._valueToSigned), _isSinged(other._isSinged)
{
}

AForm &AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
	{
		_isSinged = rhs._isSinged;
	}
	return (*this);
}

AForm::~AForm()
{
}

const std::string &AForm::getName() const
{
	return (_name);
}

int AForm::getValiueToSigned() const
{
	return (_valueToSigned);
}

int AForm::getValueToExecute() const
{
	return (_valueToExecute);
}

bool AForm::isSigned() const
{
	return (_isSinged);
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _valueToSigned)
		throw GradeTooLowException();
	_isSinged = true;
}
void AForm::checkExecution(Bureaucrat const &executor) const
{
	if (!_isSinged)
		throw ExceptionNotSignedForm();
	if (executor.getGrade() > _valueToExecute)
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade to Low for signed");
}
const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade to High for signed");
}

const char *AForm::ExceptionNotSignedForm::what() const throw()
{
	return ("Form Not be Signed");
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << "AForm \"" << f.getName() << "\" [signed: " << (f.isSigned() ? "yes" : "no") << ",grade required to sign: " << f.getValiueToSigned() << ",grade required to execute: " << f.getValueToExecute() << "]";
	return (os);
}