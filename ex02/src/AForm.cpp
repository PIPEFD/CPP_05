/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
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
    return (*this);
}

AForm::~AForm()
{
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