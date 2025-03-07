/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:13:15 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/07 18:12:37 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP

# define AFORM_HPP

# include "../inc/Bureaucrat.hpp"
# include <exception>
# include <iostream>
# include <string>

class	Bureaucrat;

class AForm
{
  private:
	const std::string _name;
	const int _gradeToExcecution;
	const int _gradeToSigned;
	bool _isSigned;

  protected:
	void checkExecution(Bureaucrat const &executor) const;

  public:
	AForm(const std::string &name, int gradeToExcecution, int gradeToSigned);
	AForm(const AForm &rhs);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

	const std::string &getName() const;
	int getGradeToExcecute() const;
	int getGradeToSigned() const;
	bool isSigned() const;

	void beSigned(const Bureaucrat &b);
	virtual void execute(Bureaucrat const &executor) const = 0;

	class GradeToHighException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	class GradeToLowException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif
