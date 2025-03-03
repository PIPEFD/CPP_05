/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:23:59 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/03 19:04:32 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Form.hpp"
#include "inc/Bureaucrat.hpp"


Form::Form(const std::string &name, int gradeToSign,  int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Constructed to default" << std::endl;
    
}

Form::Form(const Form &other) :  _name(other._name), _isSigned(_isSigned), _gradeToSign(_gradeToSign), _gradeToExecute(_gradeToExecute)
{
    std::cout << "Copy of constucted of form" << std::endl;
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
    std::cout << "Destroyed to default" << std::endl;


}
const std::string &Form::getName() const
{
    return (_name);
}

const int Form::getGradeToExecute() const
{
    return(_gradeToExecute);
}

const int Form::getGradeToSigned() const
{
    return (_gradeToSign);
}

bool Form::beSigned()
{
    if ()   
        throw 
}


