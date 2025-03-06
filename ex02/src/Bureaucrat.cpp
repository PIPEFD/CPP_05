/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pipe <pipe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:02:14 by pipe              #+#    #+#             */
/*   Updated: 2025/03/04 19:47:59 by pipe             ###   ########.fr       */
=======
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:16:27 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/06 04:16:47 by dbonilla         ###   ########.fr       */
>>>>>>> 9956512 (changes)
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
<<<<<<< HEAD

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw GradeToHighException();
    else if (grade > 150)
        throw GradeToLowException();

    _grade = grade;
}       
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
    
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
    if (this !=  &rhs)
        _name = rhs.name;
    return (*this);
}
Bureaucrat::~Bureaucrat()
{
    std::cout "Destroyed For Default" << std::endl;
    
}
        
const std::string &Bureaucrat::getName() const
{
    return (_name);
}
int Bureaucrat::getGrade() const
{
    return (_grade);   
}
void Bureaucrat::incrementGrade()
{
    if (getGrade() < 1 )
        throw GradeToHighException();
    _grade++;
       
}
void Bureaucrat::decrementGrade()
{
    if (getGrade() > 150 )
        throw GradeToHighException();
    _grade--;
    
}
void Bureaucrat::signForm(Form &form) 
{
    try
    {
        /* code */
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
                
const char *Bureaucrat::GradeToHighException::what() const throw()
=======
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
>>>>>>> 9956512 (changes)
{
    return ("Grade To High");
}

<<<<<<< HEAD
const char *Bureaucrat::GradeToLowExecption:: what() const throw()
=======
const char *Bureaucrat::GradeToLowException:: what() const throw()
>>>>>>> 9956512 (changes)
{
    return ("Grade To Low");
}

<<<<<<< HEAD
std::ostream &operator<<(const std::string name, int grade);
=======
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





>>>>>>> 9956512 (changes)

