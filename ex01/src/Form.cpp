/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:23:59 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/07 17:49:54 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"


Form::Form(const std::string &name, int gradeToSign,  int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Form Constructed " << std::endl;
    if (gradeToSign < 1 && gradeToExecute < 1)
        throw GradeToHighException();
    else if (gradeToSign > 150 && gradeToExecute > 150 )
        throw GradeToLowException();
    
}

Form::Form(const Form &other) :  _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{

}

Form &Form::operator=(const Form &rhs)
{
    if (this !=  &rhs)
    {
        _isSigned = rhs._isSigned;   
    }
    return (*this);
}

Form::~Form()
{
    std::cout << "Form Destroyed" << std::endl;


}
const std::string &Form::getName() const
{
    return (_name);
}

int Form::getGradeToExecute() const
{
    return(_gradeToExecute);
}

int Form::getGradeToSigned() const
{
    return (_gradeToSign);
}

bool Form::isSigned() const
{
    return (_isSigned);
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > _gradeToSign)
        throw GradeToLowException();
    _isSigned = true;
}

const char *Form::GradeToHighException:: what() const throw()
{
    return ("Grade to High for signed");
}
const char *Form::GradeToLowException::what() const throw()
{
    return ("Grade to low for signed");
}


std::ostream& operator<<(std::ostream& os, const Form &f) {
    os << "Form \"" << f.getName() << "\" [signed: " 
       << (f.isSigned() ? "yes" : "no")
       << ", grade required to sign: " << f.getGradeToSigned()
       << ", grade required to execute: " << f.getGradeToExecute() << "]";
    return (os);
}