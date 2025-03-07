/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:29:35 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/07 16:11:53 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "../inc/AForm.hpp"

class AForm;

class Intern
{
    public:
    Intern();
    ~Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);

    typedef AForm* (*FormCreator)(const std::string& target);
    // static AForm* createShrubbery(const std::string& target);
    // static AForm* createRobotomy(const std::string& target);
    // static AForm* createPardon(const std::string& target);
    AForm *makeForm(const std::string& formName, const std::string& target);




    // AForm* makeForm(const std::string& formName, const std::string& target);
};

#endif


