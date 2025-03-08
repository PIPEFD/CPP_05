/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:24:30 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/08 01:19:06 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTMYREQUESTFORM_HPP

# define ROBOTMYREQUESTFORM_HPP

# include "../inc/AForm.hpp"
# include <string>

class RobotomyRequestForm : public AForm
{
  private:
	const std::string _target;

  public:
    RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
	virtual ~RobotomyRequestForm();

	virtual void execute(Bureaucrat const &executor) const;
};

#endif