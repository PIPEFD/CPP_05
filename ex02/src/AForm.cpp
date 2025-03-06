/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pipe <pipe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:43:35 by pipe              #+#    #+#             */
/*   Updated: 2025/03/04 20:50:05 by pipe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
AForm::AForm(const std::string &name, int gradeToSigned, int _gradeToExecute) : _name(name), _isSigned(false), _gradeToSigned(gradeToSigned), _gradeToExecute(_gradeToExecute)
{
    std::cout << "Constructor to default" << std::endl;
    if (gradeToSigned < 1 || _gradeToExecute < 1)
        throw GradeToHighExecption();
    else if (gradeToSigned > 150 || _gradeToSigned > 150)
        throw GradeToLowExecption();
        
    
}

AForm::AForm(const AForm &other) :  _name(other._name), _gradeToSigned(other._gradeToSigned), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "Copy Constructor to Default" << std::endl;
}


AForm &AForm::operator=(const AForm &rhs)
{
    if(this != &rhs)
        _isSigned = rhs._isSigned;
=======
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:02:57 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/06 03:14:25 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"


AForm::AForm(const std::string &name, int gradeToExcecution, int gradeToSigned) : _name(name), _gradeToExcecution(gradeToExcecution), _gradeToSigned(gradeToSigned), _isSigned(false)
{
    if (gradeToExcecution < 1 || gradeToSigned < 1)
        throw GradeToHighException();
    else if (gradeToExcecution > 150 || gradeToSigned > 150)
        throw GradeToLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _gradeToExcecution(other._gradeToExcecution), _gradeToSigned(other._gradeToSigned)   
{
    std::cout << "Copy of Constructor" << std::endl;
}

AForm &AForm::operator=(const AForm &rhs)
{
    if (this != &rhs)
    {
        _isSigned = rhs._isSigned;
    }
>>>>>>> 9956512 (changes)
    return (*this);
}

AForm::~AForm()
{
<<<<<<< HEAD
    std::cout << "Destroyer To Default" << std::endl;
}

const std::string &AForm::getName() const
{
    return (_name);
}

int AForm::getGradeToExecute()   const
{
    return (_gradeToExecute);
}

int AForm::getGradeToSigned()    const
{
    return(_gradeToSigned);
}

bool AForm::isSigned()           const
{
    return(_isSigned);
}


void AForm::beSigned(const Bureaucrat &b)
{
    
}

const char *AForm::GradeToHighExecption:: what() const throw()
{
    return ("Grade To High");

}
const char *AForm::GradeToLowExecption:: what() const throw()
{
    return ("Grade To Low");   
}

std::ostream &operator<<(std::ostream os,  const Form &f)
{
    os << "" << std::endl;
    return (os);   
}
=======
    std::cout << "Destroyer to Default" << std::endl;
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
        throw GradeToLowException();
    _isSigned = true;
}

void AForm::checkExecution(Bureaucrat const &executor) const
{
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExcecution)
        throw GradeToLowException();
}

const char *AForm::GradeToHighException::what() const throw()
{
    return ("Grade to high");
}

const char *AForm::GradeToLowException::what() const throw()
{
    return ("Grade to low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("AForm is not signed");
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "AForm \"" << f.getName() << "\" [signed: " 
       << (f.isSigned() ? "yes" : "no")
       << ", grade required to sign: " << f.getGradeToSigned()
       << ", grade required to execute: " << f.getGradeToExcecute() << "]";
    return (os);
}

>>>>>>> 9956512 (changes)
